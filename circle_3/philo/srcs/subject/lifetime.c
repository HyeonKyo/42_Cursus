#include "philo.h"

void	*lifetime(void *data)
{
	t_philo	*philo;
	t_info	*inf;
	long long	cur;
	int	i;

	philo = (t_philo *)data;
	inf = philo->inf;
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
			else if (philo[i].n_eat == inf->n_must)
			{
				if (++inf->full_cnt == inf->n_must)
				{
					philo[i].cond = FULL;
					state_message(&(philo[i]));
				}
			}
			i++;
		}
		usleep(DELTA);
	}
}
