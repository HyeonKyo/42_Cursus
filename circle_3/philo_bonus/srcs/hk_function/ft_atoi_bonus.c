/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:34:28 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 21:43:04 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str, int *val)
{
	int			i;
	int			digit_len;
	long long	num;

	i = 0;
	digit_len = 0;
	num = 0;
	if (str == 0)
		return (FALSE);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i++] - '0');
		digit_len++;
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] != '\0')
		return (FALSE);
	if (digit_len > 10 || num > INT_MAX)
		return (FALSE);
	*val = (int)num;
	return (TRUE);
}
