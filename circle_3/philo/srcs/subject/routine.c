#include "philo.h"

int	check_condition(t_info *inf)
{
	if (inf->cond == DEAD || inf->cond == FULL)
		return (TRUE);
	else
		return (FALSE);
}

static int	pickup_fork(t_philo *philo, t_cond cond)
{
	t_node	**fork;

	fork = philo->inf->fork;
	while (TRUE)
	{
		if (check_condition(philo->inf))
			return (TRUE);
		pthread_mutex_lock(&(fork[philo->i]->fk_mtx));
		if (fork[philo->i]->n == AVAILABLE)
		{
			pthread_mutex_lock(&(fork[philo->left]->fk_mtx));
			pthread_mutex_lock(&(fork[philo->right]->fk_mtx));
			fork[philo->left]->n -= 1;
			pthread_mutex_unlock(&(fork[philo->left]->fk_mtx));
			fork[philo->right]->n -= 1;
			pthread_mutex_unlock(&(fork[philo->right]->fk_mtx));
			state_message(philo, cond);
			state_message(philo, cond);
			pthread_mutex_unlock(&(fork[philo->i]->fk_mtx));
			return (FALSE);
		}
		pthread_mutex_unlock(&(fork[philo->i]->fk_mtx));
		usleep(DELTA);
	}
}

static int	eating(t_philo *philo, t_cond cond)
{
	t_info		*inf;
	long long	start_eat;
	long long	cur;

	if (check_condition(philo->inf))
		return (TRUE);
	inf = philo->inf;
	save_time(&start_eat);
	state_message(philo, cond);
	if (inf->n_must > 0)
	{
		pthread_mutex_lock(&inf->full_mtx);
		philo->n_eat++;
		pthread_mutex_unlock(&inf->full_mtx);
	}
	usleep(inf->tm_eat * MILLI * 3 / 4);
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

static int	sleeping(t_philo *philo, t_cond cond)
{
	t_info		*inf;
	long long	start_sleep;
	long long	cur;

	if (check_condition(philo->inf))
		return (TRUE);
	inf = philo->inf;
	state_message(philo, cond);
	save_time(&start_sleep);
	usleep(inf->tm_sleep * MILLI * 3 / 4);
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

static int	thinking(t_philo *philo, t_cond cond)
{
	if (check_condition(philo->inf))
		return (TRUE);
	state_message(philo, cond);
	usleep(ITER);
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
		if (check_condition(philo->inf))
			return (NULL);
		if (pickup_fork(philo, GRAB))
			return (NULL);
		if (eating(philo, EATING))
			return (NULL);
		if (sleeping(philo, SLEEPING))
			return (NULL);
		if (thinking(philo, THINKING))
			return (NULL);
	}
}
