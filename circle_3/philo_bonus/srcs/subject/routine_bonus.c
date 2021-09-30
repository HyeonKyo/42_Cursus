/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:35:56 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:35:57 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	pickup_fork(t_philo *philo)
{
	//포크 두 개를 동시에 드는 원자성은 어떻게 보장?
	//두 개를 동시에 들 필요는 없는지?
	sem_wait(philo->sem.fork);
	state_message(philo, GRAB);
	sem_wait(philo->sem.fork);
	state_message(philo, GRAB);
}

static void	eating(t_philo *philo)
{
	long long	start_eat;
	long long	cur;

	save_time(&start_eat);
	state_message(philo, EATING);
	if (philo->n_must > 0)
	{
		philo->cnt_eat++;
		if (philo->cnt_eat == philo->n_must)
			sem_post(philo->sem.full);
	}
	usleep(philo->tm_eat * MILLI * 3 / 4);
	while (TRUE)
	{
		save_time(&cur);
		if (cur - start_eat >= philo->tm_eat)
		{
			philo->tm_life = cur;
			return ;
		}
		usleep(ITER);
	}
}

static void	sleeping(t_philo *philo)
{
	long long	start_sleep;
	long long	cur;

	state_message(philo, SLEEPING);
	sem_post(philo->sem.fork);
	sem_post(philo->sem.fork);
	save_time(&start_sleep);
	usleep(philo->tm_sleep * MILLI * 3 / 4);
	while (TRUE)
	{
		save_time(&cur);
		if (cur - start_sleep >= philo->tm_sleep)
			return ;
		usleep(ITER);
	}
}

static void	thinking(t_philo *philo)
{
	state_message(philo, THINKING);
	usleep(DELTA);
	return ;
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->i & ISEVEN)
		usleep((philo->tm_eat * MILLI) - DELTA);
	while (TRUE)
	{
		pickup_fork(philo);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
}
