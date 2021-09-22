#include "philo_bonus.h"

void	save_time(long long *time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*time = tv.tv_sec * MILLI + tv.tv_usec / MILLI;
}
