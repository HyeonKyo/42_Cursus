/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:19 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/24 23:59:52 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *deq)
{
	t_list		*end;
	t_list		*tmp;
	t_list		*pre;
	t_cmd_deq	*cmd;

	if (deq->cursor == deq->end_A)
		return ;
	cmd = deq->cmd;
	end = deq->end_A;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = end->data;
	link_node(tmp, deq->cursor);
	link_node(pre, tmp);
	deq->end_A = deq->end_A->next;
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

	if (deq->cursor->end_flag == 1)
		return ;
	cmd = deq->cmd;
	end = deq->end_B;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = end->data;
	link_node(tmp, deq->cursor);
	link_node(pre, tmp);
	deq->end_B = deq->end_B->prev;
	remove_node(end);
	deq->end_B->next = NULL;
	deq->cursor = tmp;
	add_command(3, "rrb", cmd);
}

void	rrr(t_deque *deq)
{
	t_list		*end;
	t_list		*tmp;
	t_list		*pre;
	t_cmd_deq	*cmd;

	cmd = deq->cmd;
	end = deq->end_A;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = end->data;
	link_node(tmp, deq->cursor);
	link_node(pre, tmp);
	deq->end_A = deq->end_A->next;
	remove_node(end);
	deq->end_A->prev = NULL;
	end = deq->end_B;
	tmp = create_node();
	tmp->data = end->data;
	link_node(tmp, deq->cursor);
	link_node(pre, tmp);
	deq->end_B = deq->end_B->prev;
	remove_node(end);
	deq->end_B->next = NULL;
	deq->cursor = tmp;
	add_command(3, "rrr", cmd);
}
