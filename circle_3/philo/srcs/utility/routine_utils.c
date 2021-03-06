/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:15 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/10/01 15:50:32 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_fork(t_philo *philo)
{
	t_mutex	*fork;

	fork = philo->inf->fork;
	pthread_mutex_lock(&(fork[philo->i]));
	if (state_message(philo, GRAB))
	{
		pthread_mutex_unlock(&(fork[philo->i]));
		return (TRUE);
	}
	/*
	여기에 왼쪽의 왼쪽 포크 값 확인
	*/
	pthread_mutex_lock(&(fork[philo->right]));
	if (state_message(philo, GRAB))
	{
		putdown_fork(philo);
		return (TRUE);
	}
	return (FALSE);
}

int	print_grap(t_philo *philo)
{
	int	i;

	i = 2;
	while (i--)
		if (state_message(philo, GRAB))
			return (putdown_fork(philo));
	return (FALSE);
}

int	putdown_fork(t_philo *philo)
{
	t_mutex	*fork;

	fork = philo->inf->fork;
	pthread_mutex_unlock(&(fork[philo->i]));
	pthread_mutex_unlock(&(fork[philo->right]));
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
