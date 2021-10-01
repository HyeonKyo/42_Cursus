/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:15 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/10/01 16:04:13 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork(t_philo *philo)
{
	t_fork	*fork;

	fork = philo->inf->fork;
	while (TRUE)
	{
		if (check_condition(philo->inf))
			return (TRUE);
		pthread_mutex_lock(&(fork[philo->i].fk_mtx));
		fork[philo->i].flag ^= TRUE;
		if (state_message(philo, GRAB))
		{
			pthread_mutex_unlock(&(fork[philo->i].fk_mtx));
			return (TRUE);
		}
		if (fork[philo->left].flag)
		{
			pthread_mutex_unlock(&(fork[philo->i].fk_mtx));
			fork[philo->i].flag ^= TRUE;
			usleep(DELTA);
			continue ;
		}
		pthread_mutex_lock(&(fork[philo->right].fk_mtx));
		if (state_message(philo, GRAB))
			return (putdown_fork(philo));
		return (FALSE);
	}
}

int	putdown_fork(t_philo *philo)
{
	t_fork	*fork;

	fork = philo->inf->fork;
	pthread_mutex_unlock(&(fork[philo->i].fk_mtx));
	fork[philo->i].flag ^= TRUE;
	pthread_mutex_unlock(&(fork[philo->right].fk_mtx));
	return (TRUE);
}

void	plus_eat_count(t_philo *philo)
{
	if (philo->inf->n_must > 0)
	{
		pthread_mutex_lock(&philo->inf->full_mtx);
		philo->n_eat++;
		pthread_mutex_unlock(&philo->inf->full_mtx);
	}
}
