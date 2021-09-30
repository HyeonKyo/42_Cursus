/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:36:33 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:36:34 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	print_state(t_cond cond)
{
	if (cond == EATING)
	{
		ft_putstr("\033[1;37;42m", STDOUT_FILENO);
		ft_putendl("is eating\033[0;0m", STDOUT_FILENO);
	}
	else if (cond == THINKING)
	{
		ft_putendl("is thinking", STDOUT_FILENO);
	}
	else if (cond == SLEEPING)
	{
		ft_putendl("is sleeping", STDOUT_FILENO);
	}
	else if (cond == GRAB)
	{
		ft_putstr("\033[1;33m", STDOUT_FILENO);
		ft_putendl("has taken a fork\033[0;0m", STDOUT_FILENO);
	}
	else if (cond == DEAD)
	{
		ft_putstr("\033[1;31m", STDOUT_FILENO);
		ft_putendl("died\033[0;0m", STDOUT_FILENO);
		return (TRUE);
	}
	return (FALSE);
}
