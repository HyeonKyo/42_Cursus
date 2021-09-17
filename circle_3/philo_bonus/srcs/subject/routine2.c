#include "philo.h"

void	putdown_fork(t_philo *philo)
{
	t_node	**fork;

	fork = philo->inf->fork;
	pthread_mutex_lock(&(fork[philo->left]->fk_mtx));
	pthread_mutex_lock(&(fork[philo->right]->fk_mtx));
	fork[philo->left]->n += 1;
	pthread_mutex_unlock(&(fork[philo->left]->fk_mtx));
	fork[philo->right]->n += 1;
	pthread_mutex_unlock(&(fork[philo->right]->fk_mtx));
}
