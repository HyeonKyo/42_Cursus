#include "philo.h"

void	putdown_fork(t_philo *philo)
{
	t_info	*inf;

	inf = philo->inf;
	pthread_mutex_lock(&(inf->fk_mtx));
	inf->fork[philo->left] += 1;
	inf->fork[philo->right] += 1;
	pthread_mutex_unlock(&(inf->fk_mtx));
	philo->priority = GOOD;
	philo->cond = SLEEPING;
}
