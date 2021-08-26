/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:55 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 16:56:59 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	*deq;

	if (ac <= 1)
		input_error();
	deq = make_stack(ac, av);
	sort(deq);
	while (optimize_command(deq->cmd))
		;
	print_cmd(deq->cmd);
	exit(0);
	return (0);
}
