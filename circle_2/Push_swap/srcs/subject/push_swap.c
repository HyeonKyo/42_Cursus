/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:55 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/07 00:29:46 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	*deq;

	if (ac <= 1)
		return (1);
	deq = make_stack(ac, av);
	sort(deq);
	while (optimize_command(deq->cmd))
		;
	print_cmd(deq->cmd);
	clear_deque(deq);
	return (0);
}
