#include "philo.h"

void	pickup_fork(t_philo *philo)
{
	t_info	*inf;

	inf = philo->inf;
	while (TRUE)
	{
		pthread_mutex_lock(&(inf->fk_mtx));
		if (philo->i & ISEVEN)
			usleep(DELTA);
		if (inf->fork[philo->i] == AVAILABLE)
		{
			save_time(&(philo->tm_save));
			state_message(philo);
			inf->fork[philo->left] -= 1;
			state_message(philo);
			inf->fork[philo->right] -= 1;
			pthread_mutex_unlock(&(inf->fk_mtx));
			philo->cond = EATING;
			return ;
		}
		else
		{
			pthread_mutex_unlock(&(inf->fk_mtx));
			usleep(DELTA);
		}
	}
}

void	putdown_fork(t_philo *philo)
{
	t_info	*inf;

	inf = philo->inf;
	pthread_mutex_lock(&(inf->fk_mtx));
	inf->fork[philo->left] += 1;
	inf->fork[philo->right] += 1;
	pthread_mutex_unlock(&(inf->fk_mtx));
	philo->cond = SLEEPING;
}

void	eating(t_philo *philo)
{
	t_info		*inf;
	long long	start_eat;
	long long	cur;

	inf = philo->inf;
	save_time(&start_eat);
	philo->tm_save = start_eat;
	state_message(philo);
	pthread_mutex_lock(&inf->full_mtx);
	philo->n_eat++;
	pthread_mutex_unlock(&inf->full_mtx);
	usleep(inf->tm_eat * MILLI / 2);
	while (TRUE)
	{
		save_time(&cur);
		if (cur - start_eat >= inf->tm_eat)
		{
			save_time(&(philo->tm_life));
			putdown_fork(philo);
			return ;
		}
		usleep(DELTA);
	}
}

void	sleeping(t_philo *philo)
{
	t_info		*inf;
	long long	start_sleep;
	long long	cur;

	inf = philo->inf;
	save_time(&start_sleep);
	philo->tm_save = start_sleep;
	state_message(philo);
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

void	thinking(t_philo *philo)
{
	save_time(&(philo->tm_save));
	state_message(philo);
	philo->cond = GRAB;
}


void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->inf->n_philo == 1)//철학자 1명일 때 예외처리
		usleep(philo->inf->tm_die * MILLI);
	while (TRUE)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
