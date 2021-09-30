/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:36:41 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:36:42 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	save_time(long long *time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	*time = tv.tv_sec * MILLI + tv.tv_usec / MILLI;
}
