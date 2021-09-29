/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:36 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/29 14:37:37 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_initialization(t_philo **philo, t_info *inf)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * inf->n_philo);
	if (merror(*philo) == ERROR)
		return (ERROR);
	i = 0;
	while (i < inf->n_philo)
	{
		(*philo)[i].i = i;
		(*philo)[i].left = i - 1;
		if ((*philo)[i].left < 0)
			(*philo)[i].left = inf->n_philo - 1;
		(*philo)[i].right = i + 1;
		if ((*philo)[i].right == inf->n_philo)
			(*philo)[i].right = 0;
		(*philo)[i].num = i + 1;
		(*philo)[i].n_eat = 0;
		(*philo)[i++].inf = inf;
	}
	return (NORMAL);
}

static int	make_fork(t_info *inf)
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
		cur->next = new;
		new->prev = cur;
		cur = cur->next;
	}
	return (NORMAL);
}

int	setup_dinner(t_philo **philo, t_info *inf)
{
	inf->cond = LIFE;
	inf->full_cnt = 0;
	if (pthread_mutex_init(&(inf->full_mtx), NULL)
		|| pthread_mutex_init(&(inf->pt_mtx), NULL))
	{
		ft_putendl("Mutex error", STDERR_FILENO);
		return (ERROR);
	}
	if (make_fork(inf) == ERROR || philo_initialization(philo, inf) == ERROR)
	{
		free_fork(inf);
		return (ERROR);
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
