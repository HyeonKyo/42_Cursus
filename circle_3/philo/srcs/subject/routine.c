#include "philo.h"

static void	pickup_fork(t_philo *philo)
{
	t_info	*inf;

	inf = philo->inf;
	while (TRUE)
	{
		pthread_mutex_lock(&(inf->fk_mtx));
		if (inf->fork[philo->i] == AVAILABLE)
		{
			state_message(philo);
			state_message(philo);
			inf->fork[philo->left] -= 1;
			inf->fork[philo->right] -= 1;
			pthread_mutex_unlock(&(inf->fk_mtx));
			philo->cond = EATING;
			return ;
		}
		pthread_mutex_unlock(&(inf->fk_mtx));
		usleep(DELTA);
	}
}

static void	eating(t_philo *philo)
{
	t_info		*inf;
	long long	start_eat;
	long long	cur;

	inf = philo->inf;
	state_message(philo);
	save_time(&start_eat);
	if (inf->n_must > 0)
	{
		pthread_mutex_lock(&inf->full_mtx);
		philo->n_eat++;
		pthread_mutex_unlock(&inf->full_mtx);
	}
	usleep(inf->tm_eat * MILLI - 2);
	while (TRUE)
	{
		save_time(&cur);
		if (cur - start_eat >= inf->tm_eat)
		{
			philo->tm_life = cur;
			putdown_fork(philo);
			return ;
		}
		usleep(DELTA);
	}
}

static void	sleeping(t_philo *philo)
{
	t_info		*inf;
	long long	start_sleep;
	long long	cur;

	inf = philo->inf;
	state_message(philo);
	save_time(&start_sleep);
	usleep(inf->tm_sleep * MILLI / 2);
	while (TRUE)
	{
		save_time(&cur);
		if (cur - start_sleep >= inf->tm_sleep)
		{
			philo->cond = THINKING;
			return ;
		}
		usleep(DELTA);
	}
}

static void	thinking(t_philo *philo)
{
	state_message(philo);
	usleep(DELTA);
	philo->cond = GRAB;
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->inf->n_philo == 1)//철학자 1명일 때 예외처리
		usleep(philo->inf->tm_die * MILLI);
	if (philo->i & ISEVEN)
		usleep(philo->inf->tm_eat * MILLI - DELTA);//짝수 철학자는 홀수 철학자가 어느정도 먹었을 때 부터 실행
	while (TRUE)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
