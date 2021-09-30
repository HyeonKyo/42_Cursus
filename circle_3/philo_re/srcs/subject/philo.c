/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:36:51 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/29 14:36:53 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	save_arg(int ac, char **av, t_info *inf)
{
	if (!(ft_atoi(av[1], &inf->n_philo) && ft_atoi(av[2], &inf->tm_die)
			&& ft_atoi(av[3], &inf->tm_eat) && ft_atoi(av[4], &inf->tm_sleep)))
		return (FALSE);
	if (ac == 6)
	{
		if (!ft_atoi(av[5], &inf->n_must))
			return (FALSE);
	}
	else
		inf->n_must = -1;
	return (TRUE);
}

void	dinning(t_philo *philo)
{
	int		i;
	t_info	*inf;

	inf = philo->inf;
	save_time(&inf->begin);
	i = -1;
	while (++i < inf->n_philo)
	{
		philo[i].tm_life = inf->begin;
		pthread_create(&(philo[i].th), NULL, routine, &(philo[i]));
		pthread_create(&(philo[i].ck), NULL, lifetime, &(philo[i]));
	}
	i = -1;
	while (++i < inf->n_philo)
	{
		pthread_join(philo[i].th, NULL);
		pthread_join(philo[i].ck, NULL);
	}
}

static void	finish_dinning(t_philo *philo, t_info *inf)
{
	if (pthread_mutex_destroy(&(inf->full_mtx))
		|| pthread_mutex_destroy(&(inf->pt_mtx)))
		ft_putendl("Mutex error", STDERR_FILENO);
	free_fork(inf);
	free(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	inf;

	if (!(ac == 5 || ac == 6) || !save_arg(ac, av, &inf))
		return (usage());
	if (setup_dinner(&philo, &inf) == ERROR)
		return (ERROR);
	dinning(philo);
	finish_dinning(philo, &inf);
	return (0);
}
