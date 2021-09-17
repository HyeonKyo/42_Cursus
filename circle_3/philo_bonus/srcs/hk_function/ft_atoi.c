/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:30:21 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/19 22:06:34 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *val)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str == 0)
		return (FALSE);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (FALSE);
	*val = num;
	return (TRUE);
}
