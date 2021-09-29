/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:15 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/29 14:37:16 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	plus_eat_count(t_philo *philo)
{
	if (philo->inf->n_must > 0)
	{
		pthread_mutex_lock(&philo->inf->full_mtx);
		philo->n_eat++;
		pthread_mutex_unlock(&philo->inf->full_mtx);
	}
}
