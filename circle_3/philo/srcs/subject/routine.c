#include "philo.h"

static void	get_fork(t_philo *philo)
{
	t_node	**fork;

	fork = philo->inf->fork;
	pthread_mutex_lock(&(fork[philo->left]->fk_mtx));
	pthread_mutex_lock(&(fork[philo->right]->fk_mtx));
	fork[philo->left]->n -= 1;
	pthread_mutex_unlock(&(fork[philo->left]->fk_mtx));
	fork[philo->right]->n -= 1;
	pthread_mutex_unlock(&(fork[philo->right]->fk_mtx));
}

static int	pickup_fork(t_philo *philo)
{
	int		i;
	t_node	**fork;

	fork = philo->inf->fork;
	i = -1;
	while (TRUE)
	{
		if (check_condition(philo->inf))
			return (TRUE);
		pthread_mutex_lock(&(fork[philo->i]->fk_mtx));
		if (fork[philo->i]->n == AVAILABLE)
		{
			get_fork(philo);
			while (++i < AVAILABLE)
			{
				if (state_message(philo, GRAB))
				{
					pthread_mutex_unlock(&(fork[philo->i]->fk_mtx));
					return (TRUE);
				}
			}
			pthread_mutex_unlock(&(fork[philo->i]->fk_mtx));
			return (FALSE);
		}
		pthread_mutex_unlock(&(fork[philo->i]->fk_mtx));
		usleep(ITER);
	}
}

static int	eating(t_philo *philo)
{
	t_info		*inf;
	long long	start_eat;
	long long	cur;

	inf = philo->inf;
	save_time(&start_eat);
	if (state_message(philo, EATING))
		return (TRUE);
	if (inf->n_must > 0)
	{
		pthread_mutex_lock(&inf->full_mtx);
		philo->n_eat++;
		pthread_mutex_unlock(&inf->full_mtx);
	}
	//usleep(inf->tm_eat * MILLI * 3 / 4);철학자가 죽을때 10ms안에 죽어야 하므로 이 부분은 빼야함.
	while (TRUE)
	{
		if (check_condition(philo->inf))
			return (TRUE);
		save_time(&cur);
		if (cur - start_eat >= inf->tm_eat)
		{
			philo->tm_life = cur;
			putdown_fork(philo);
			return (FALSE);
		}
		usleep(ITER);
	}
}

static int	sleeping(t_philo *philo)
{
	t_info		*inf;
	long long	start_sleep;
	long long	cur;

	inf = philo->inf;
	if (state_message(philo, SLEEPING))
		return (TRUE);
	save_time(&start_sleep);
	//usleep(inf->tm_sleep * MILLI * 3 / 4);
	while (TRUE)
	{
		if (check_condition(philo->inf))
			return (TRUE);
		save_time(&cur);
		if (cur - start_sleep >= inf->tm_sleep)
			return (FALSE);
		usleep(ITER);
	}
}

static int	thinking(t_philo *philo)
{
	if (state_message(philo, THINKING))
		return (TRUE);
	usleep(DELTA);
	return (FALSE);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->inf->n_philo == 1)//철학자 1명일 때 예외처리
		usleep(philo->inf->tm_die * MILLI);
	if (philo->i & ISEVEN)
		usleep((philo->inf->tm_eat * MILLI) - DELTA);//짝수 철학자는 홀수 철학자가 어느정도 먹었을 때 부터 실행
	while (TRUE)
	{
		if (pickup_fork(philo))
			return (NULL);
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
}
