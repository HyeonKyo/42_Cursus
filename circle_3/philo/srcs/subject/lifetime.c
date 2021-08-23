#include "philo.h"

static void	full_check(t_philo *philo)
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
			philo->cond = FULL;
			state_message(philo);
		}
	}
	pthread_mutex_unlock(&inf->full_mtx);
}

void	*lifetime(void *data)
{
	t_philo		*philo;
	t_info		*inf;
	long long	cur;
	long long	life;

	philo = (t_philo *)data;
	inf = philo->inf;
	usleep(DELTA);//철학자(쓰레드)생성이 되는 시간을 기다리고 수명 체크 시작
	while (TRUE)
	{
		save_time(&cur);
		life = cur - philo->tm_life;
		if (philo->priority == GOOD && life >= inf->tm_die * 4 / 5)//우선 순위의 기준
			philo->priority = HUNGRY;
		if (philo->priority == HUNGRY)
		{
			if (life >= inf->tm_die)
			{
				philo->cond = DEAD;
				state_message(philo);
			}
		}
		full_check(philo);
		usleep(DELTA);
	}
}
