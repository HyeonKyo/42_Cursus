/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:35:04 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:35:05 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	print_num(int n, int fd, int *flag)
{
	char	c;

	if (n == 0 && *flag == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == 0)
		return ;
	*flag = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	print_num(n / 10, fd, flag);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr(int n, int fd)
{
	int	flag;

	flag = 0;
	print_num(n, fd, &flag);
}
