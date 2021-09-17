#include "philo.h"

int	make_fork(t_info *inf)
{
	int	i;
	t_node	*head;
	t_node	*cur;
	t_node	*new;

	inf->fork = (t_node **)malloc(sizeof(t_node *) * inf->n_philo);
	if (merror(inf->fork))
		return (ERROR);
	memset(inf->fork, 0, sizeof(t_node *) * inf->n_philo);
	head = create_node();
	if (merror(head))
		return (ERROR);
	inf->fork[0] = head;
	cur = head;
	i = 0;
	while (++i < inf->n_philo)
	{
		new = create_node();
		if (merror(new))
			return (ERROR);
		inf->fork[i] = new;
		new->n = AVAILABLE;
		new->next = NULL;
		cur->next = new;
		new->prev = cur;
		cur = cur->next;
	}
	return (NORMAL);
}

void	free_fork(t_info *inf)
{
	int	i;
	t_node **fork;

	fork = inf->fork;
	i = 0;
	while (fork[i] && i < inf->n_philo)
	{
		pthread_mutex_destroy(&(fork[i]->fk_mtx));
		free(fork[i++]);
	}
	free(fork);
	inf->fork = NULL;
}
