/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:00 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/25 15:08:47 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *deq)
{
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	if (deq->cursor == deq->end_A)
		return ;
	cmd = deq->cmd;
	top = deq->cursor->prev;
	tmp = create_node();
	tmp->data = top->data;
	link_node(tmp, deq->end_A);
	remove_node(top);
	deq->end_A = tmp;
	add_command(2, "ra", cmd);
}

void	rb(t_deque *deq)
{
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	if (deq->cursor->end_flag == TRUE)
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
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	cmd = deq->cmd;
	top = deq->cursor->prev;
	tmp = create_node();
	tmp->data = top->data;
	link_node(tmp, deq->end_A);
	remove_node(top);
	deq->end_A = tmp;
	top = deq->cursor;
	tmp = create_node();
	tmp->data = top->data;
	link_node(deq->end_B, tmp);
	link_node(tmp, deq->end_node);
	remove_node(top);
	deq->end_B = tmp;
	add_command(2, "rr", cmd);
}

