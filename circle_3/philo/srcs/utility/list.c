#include "philo.h"

t_node	*create_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	if (pthread_mutex_init(&(new->fk_mtx), NULL))
	{
		ft_putendl("Mutex error", STDERR_FILENO);
		free(new);
		return (NULL);
	}
	memset(new, 0, sizeof(t_node));
	new->n = AVAILABLE;
	return (new);
}
