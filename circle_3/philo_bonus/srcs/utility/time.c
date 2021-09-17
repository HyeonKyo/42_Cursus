#include "philo_bonus.h"

void	save_time(long long *time)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		error("Fail to get time");
	*time = tv.tv_sec * MILLI + tv.tv_usec / MILLI;
}
