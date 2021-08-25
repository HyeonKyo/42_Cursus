/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:00 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 00:58:05 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *deq)
{
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	if (deq->size_a <= 1)
		return ;
	cmd = deq->cmd;
	top = deq->cursor->prev;
	tmp = create_node();
	tmp->data = top->data;
	link_node(tmp, deq->end_A);
	deq->end_A = tmp;
	remove_node(top);
	add_command(2, "ra", cmd);
}

void	rb(t_deque *deq)
{
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	if (deq->size_b <= 1)
		return ;
	cmd = deq->cmd;
	top = deq->cursor;
	tmp = create_node();
	tmp->data = top->data;
	link_node(deq->end_B, tmp);
	link_node(tmp, deq->end_node);
	remove_node(top);
	deq->end_B = tmp;
	add_command(2, "rb", cmd);
}

void	rr(t_deque *deq)
{
	t_cmd_deq	*cmd;

	cmd = deq->cmd;
	ra(deq);
	rb(deq);
	del_cmd_last_node(cmd);
	del_cmd_last_node(cmd);
	add_command(2, "rr", cmd);
}

