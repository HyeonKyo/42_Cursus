#include "philo.h"

void	*lifetime(void *data)
{
	t_philo	*philo;
	t_info	*inf;
	long long	cur;
	int	i;

	philo = (t_philo *)data;
	inf = philo->inf;
	usleep(DELTA * 10);//철학자(쓰레드)생성이 되는 시간을 기다리고 수명 체크 시작
	while (TRUE)
	{
		save_time(&cur);
		i = 0;
		while (i < inf->n_philo)
		{
			if (cur - philo[i].tm_life >= inf->tm_die)
			{
				philo[i].cond = DEAD;
				state_message(&(philo[i]));
			}
			else
			{
				pthread_mutex_lock(&inf->full_mtx);
				if (philo[i].n_eat == inf->n_must)
				{
					inf->full_cnt++;
					philo[i].n_eat++;
					if (inf->full_cnt == inf->n_philo)
					{
						usleep((inf->tm_eat * MILLI) + DELTA);//마지막으로 먹을 시간 주기
						philo[i].cond = FULL;
						state_message(&(philo[i]));
					}
				}
				pthread_mutex_unlock(&inf->full_mtx);
			}
			i++;
		}
		usleep(DELTA);
	}
}
