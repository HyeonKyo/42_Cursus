#include "philo.h"

static int	full_check(t_philo *philo)
{
	t_info	*inf;

	inf = philo->inf;
	pthread_mutex_lock(&inf->full_mtx);
	if (philo->n_eat == inf->n_must)
	{
		inf->full_cnt++;
		philo->n_eat++;//full_cnt는 한 철학자 당 한 번만 카운트 해줘야 하므로
		if (inf->full_cnt == inf->n_philo)
		{
			usleep(inf->tm_eat * MILLI);//마지막으로 먹을 시간 주기
			inf->cond = FULL;
			state_message(philo, FULL);
			return (1);
		}
	}
	pthread_mutex_unlock(&inf->full_mtx);
	return (0);
}

void	*lifetime(void *data)
{
	t_philo		*philo;
	t_info		*inf;
	long long	cur;

	philo = (t_philo *)data;
	inf = philo->inf;
	usleep(inf->tm_die * MILLI * 3 / 4);//철학자(쓰레드)생성이 되는 시간을 기다리고 수명 체크 시작
	while (TRUE)
	{
		if (check_condition(inf))
			return (NULL);
		save_time(&cur);
		if (cur - philo->tm_life >= inf->tm_die)
		{
			inf->cond = DEAD;
			state_message(philo, DEAD);
			return (NULL);
		}
		if (full_check(philo))
			return (NULL);
		usleep(DELTA);
	}
}
