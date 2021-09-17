#include "philo_bonus.h"

void	*full_check(void *data)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)data;
	i = 1;
	while (i < philo->n_philo)
	{
		sem_wait(philo->sem.full);
		i++;
	}
	sem_wait(philo->sem.full);
	state_message(philo, FULL);
	sem_post(philo->sem.die);
	exit(NORMAL);
}

void	*die_check(void *data)
{
	t_philo		*philo;
	long long	cur;

	philo = (t_philo *)data;
	while (TRUE)
	{
		save_time(&cur);
		if (cur - philo->tm_life >= philo->tm_die)
		{
			state_message(philo, DEAD);
			sem_post(philo->sem.die);//메인 쓰레드에서 wait중, 들어가면 종료 시그널로 모든 철학자를 죽여줌.
			exit(NORMAL);
		}
		usleep(ITER);
	}
}
