#include "philo.h"

void	make_fork(t_info *inf)
{
	int	i;
	t_node	*head;
	t_node	*cur;
	t_node	*new;

	inf->fork = (t_node **)malloc(sizeof(t_node *) * inf->n_philo);
	merror(inf->fork);
	head = (t_node *)malloc(sizeof(t_node));
	merror(head);
	head->n = AVAILABLE;
	head->prev = NULL;
	inf->fork[0] = head;
	cur = head;
	i = 0;
	while (++i < inf->n_philo)
	{
		new = (t_node *)malloc(sizeof(t_node));
		merror(new);
		inf->fork[i] = new;
		new->n = AVAILABLE;
		new->next = NULL;
		cur->next = new;
		new->prev = cur;
		cur = cur->next;
	}
}
