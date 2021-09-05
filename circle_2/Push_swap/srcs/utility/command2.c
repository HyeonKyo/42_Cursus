/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:00 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/04 17:17:44 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_deque *deq)
{
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	if (deq->size_a <= 1)
		return (0);
	cmd = deq->cmd;
	top = deq->cursor->prev;
	tmp = create_node();
	tmp->data = top->data;
	link_node(tmp, deq->end_A);
	deq->end_A = tmp;
	remove_node(top);
	add_command(2, "ra", cmd);
	return (1);
}

int	rb(t_deque *deq)
{
	t_list		*top;
	t_list		*tmp;
	t_cmd_deq	*cmd;

	if (deq->size_b <= 1)
		return (0);
	cmd = deq->cmd;
	top = deq->cursor;
	deq->cursor = deq->cursor->next;
	tmp = create_node();
	tmp->data = top->data;
	link_node(deq->end_B, tmp);
	link_node(tmp, deq->end_node);
	remove_node(top);
	deq->end_B = tmp;
	add_command(2, "rb", cmd);
	return (1);
}

void	rr(t_deque *deq)
{
	t_cmd_deq	*cmd;
	int			i;

	cmd = deq->cmd;
	i = ra(deq);
	i += rb(deq);
	while (i--)
		del_cmd_last_node(cmd);
	add_command(2, "rr", cmd);
}
