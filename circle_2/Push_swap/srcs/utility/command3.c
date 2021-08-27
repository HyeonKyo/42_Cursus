/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:19 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 16:43:08 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *deq)
{
	t_list		*end;
	t_list		*tmp;
	t_list		*pre;
	t_cmd_deq	*cmd;

	if (deq->size_a <= 1)
		return ;
	cmd = deq->cmd;
	end = deq->end_A;
	deq->end_A = deq->end_A->next;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = end->data;
	link_node(tmp, deq->cursor);
	link_node(pre, tmp);
	remove_node(end);
	deq->end_A->prev = NULL;
	add_command(3, "rra", cmd);
}

void	rrb(t_deque *deq)
{
	t_list		*end;
	t_list		*tmp;
	t_list		*pre;
	t_cmd_deq	*cmd;

	if (deq->size_b <= 1)
		return ;
	cmd = deq->cmd;
	end = deq->end_B;
	deq->end_B = deq->end_B->prev;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = end->data;
	link_node(tmp, deq->cursor);
	link_node(pre, tmp);
	remove_node(end);
	deq->cursor = deq->cursor->prev;
	add_command(3, "rrb", cmd);
}

void	rrr(t_deque *deq)
{
	t_cmd_deq	*cmd;

	cmd = deq->cmd;
	rra(deq);
	rrb(deq);
	del_cmd_last_node(cmd);
	del_cmd_last_node(cmd);
	add_command(3, "rrr", cmd);
}
