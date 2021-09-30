/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:04 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 21:19:55 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	pickup_fork(t_philo *philo)
{
	int		i;
	t_mutex	*fork;

	fork = philo->inf->fork;
	i = -1;
	if (check_condition(philo->inf))
		return (TRUE);
	get_fork(philo);
	return (print_grap(philo));
}

static int	eating(t_philo *philo)
{
	t_info		*inf;
	long long	start_eat;
	long long	cur;

	inf = philo->inf;
	save_time(&start_eat);
	if (state_message(philo, EATING))
		return (putdown_fork(philo));
	plus_eat_count(philo);
	while (TRUE)
	{
		if (check_condition(philo->inf))
			return (putdown_fork(philo));
		save_time(&cur);
		if (cur - start_eat >= inf->tm_eat)
		{
			philo->tm_life = cur;
			return (FALSE);
		}
		usleep(ITER);
	}
}

static int	sleeping(t_philo *philo)
{
	t_info		*inf;
	long long	start_sleep;
	long long	cur;

	inf = philo->inf;
	if (state_message(philo, SLEEPING))
		return (putdown_fork(philo));
	save_time(&start_sleep);
	putdown_fork(philo);
	while (TRUE)
	{
		if (check_condition(inf))
			return (TRUE);
		save_time(&cur);
		if (cur - start_sleep >= inf->tm_sleep)
			return (FALSE);
		usleep(ITER);
	}
}

static int	thinking(t_philo *philo)
{
	if (state_message(philo, THINKING))
		return (TRUE);
	return (FALSE);
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->inf->n_philo == 1)//철학자 1명일 때 예외처리
		usleep(philo->inf->tm_die * MILLI);
	if (philo->i & ISEVEN)
		usleep((philo->inf->tm_eat - DELTA) * MILLI);//짝수 철학자는 홀수 철학자가 어느정도 먹었을 때 부터 실행
	while (TRUE)
	{
		if (pickup_fork(philo))
			return (NULL);
		if (eating(philo))
			return (NULL);
		if (sleeping(philo))
			return (NULL);
		if (thinking(philo))
			return (NULL);
	}
}
