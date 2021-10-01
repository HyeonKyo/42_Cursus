/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 14:37:28 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 21:54:35 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	merror(void *ret)
{
	if (ret == NULL)
	{
		ft_putstr("\033[1;31m", STDERR_FILENO);
		ft_putendl("\nMalloc Error!\033[0;0m", STDERR_FILENO);
		return (ERROR);
	}
	return (NORMAL);
}

int	usage(void)
{
	ft_putstr("\033[1;31m", STDERR_FILENO);
	ft_putendl("\nInput Error!", STDERR_FILENO);
	ft_putstr("\033[1;37m", STDERR_FILENO);
	ft_putstr("\nUsage : ./philo [number of philo] ", STDERR_FILENO);
	ft_putstr("[time to die] [time to eat] ", STDERR_FILENO);
	ft_putendl("[time to sleep]", STDERR_FILENO);
	ft_putstr("([number_of_times_each", STDERR_FILENO);
	ft_putendl("_philosopher_must_eat])", STDERR_FILENO);
	ft_putstr("\nAll arguments are positive ", STDERR_FILENO);
	ft_putendl("and within an integer range.\n", STDERR_FILENO);
	return (ERROR);
}
