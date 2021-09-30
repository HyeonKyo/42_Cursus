/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifetime_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:35:42 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:35:43 by hyeonkki         ###   ########.fr       */
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

void	check_main(t_philo *philo, pid_t *pid_array)
{
	int	i;

	usleep(100);
	i = -1;
	if (philo->n_must > 0)
	{
		if (pthread_create(&philo->th_full, NULL, full_check, philo)
			|| pthread_detach(philo->th_full))
		{
			sem_wait(philo->sem.print);
			ft_putendl("Thread error!", STDERR_FILENO);
			sem_post(philo->sem.die);
		}
	}
	sem_wait(philo->sem.die);
	while (++i < philo->n_philo)
		kill(pid_array[i], SIGTERM);
	i = -1;
	while (++i < philo->n_philo)
		waitpid(0, NULL, 0);
}
