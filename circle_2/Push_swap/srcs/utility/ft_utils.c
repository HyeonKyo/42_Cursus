/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:39 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/27 14:45:52 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_number(int *a, int *b)
{
	int	tmp;

	if (!a || !b)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	find_max(int n1, int n2, int n3)
{
	if (n1 >= n2)
	{
		if (n1 >= n3)
			return (n1);
		else
			return (n3);
	}
	else
	{
		if (n2 >= n3)
			return (n2);
		else
			return (n3);
	}
}

int	find_min(int n1, int n2, int n3)
{
	if (n1 <= n2)
	{
		if (n1 <= n3)
			return (n1);
		else
			return (n3);
	}
	else
	{
		if (n2 <= n3)
			return (n2);
		else
			return (n3);
	}
}
