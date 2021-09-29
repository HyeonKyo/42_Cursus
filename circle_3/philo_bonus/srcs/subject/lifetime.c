/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifetime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:03:22 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/29 17:03:25 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*full_check(void *data)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)data;
	i = 1;
	while (i < philo->n_philo)
	{
		sem_wait(philo->sem.full);
		i++;
	}
	sem_wait(philo->sem.full);
	usleep(philo->tm_eat * MILLI + 1);
	state_message(philo, FULL);
	sem_post(philo->sem.die);
	return (NULL);
}

void	*die_check(void *data)
{
	t_philo		*philo;
	long long	cur;

	philo = (t_philo *)data;
	while (TRUE)
	{
		save_time(&cur);
		if (cur - philo->tm_life >= philo->tm_die)
		{
			state_message(philo, DEAD);
			sem_post(philo->sem.die);
			return (NULL);
		}
		usleep(ITER);
	}
}
