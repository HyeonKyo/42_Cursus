/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:55 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/15 22:39:21 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_deque	*deq_A;
	t_deque	*deq_B;
	t_info	*info;

	if (ac <= 1)//ac = 2 -> 인자 1개 => "1 2 34" 이런식으로 여러개 들어올 수 있음.
		return (1);
	deq_B = make_stack(ac, av, &deq_A);
	info = q_sort(deq_A, deq_B);
	while (optimize_command(info->cmd))
		;
	print_cmd(info);
	clear_info(info);
	return (0);
}
