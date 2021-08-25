/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:55 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/25 23:46:33 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	*deq;

	if (ac <= 1)
		input_error();
	deq = make_stack(ac, av);
	print_deq(deq);
	sort(deq);
	print_deq(deq);
	/*
	2. sort
	3. optimizing
	*/
	return (0);
}
