/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_dinning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:36 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/10/01 16:53:02 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	zero_check(t_info *inf)
{
	if (!inf->n_philo || !inf->tm_die || !inf->tm_eat
		|| !inf->tm_sleep || !inf->n_must)
		return (ERROR);
	return (NORMAL);
}

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

	inf->fork = (t_fork *)malloc(sizeof(t_fork) * inf->n_philo);
	if (merror(inf->fork))
		return (ERROR);
	i = -1;
	while (++i < inf->n_philo)
	{
		if (pthread_mutex_init(&(inf->fork[i].fk_mtx), NULL))
		{
			ft_putendl("Mutex error", STDERR_FILENO);
			return (ERROR);
		}
		inf->fork[i].flag = FALSE;
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
	if (inf->fork)
		free(inf->fork);
	inf->fork = NULL;
}
