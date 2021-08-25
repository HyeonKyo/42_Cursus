/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:15 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/25 13:42:05 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *deq)
{
	int			tmp;
	t_cmd_deq	*cmd;
	t_list		*top_A;

	cmd = deq->cmd;
	top_A = deq->cursor->prev;
	tmp = top_A->data;
	top_A->data = top_A->prev->data;
	top_A->prev->data = tmp;
	add_command(2, "sa", cmd);
}

void	sb(t_deque *deq)
{
	int			tmp;
	t_cmd_deq	*cmd;
	t_list		*top_B;

	cmd = deq->cmd;
	top_B = deq->cursor;
	tmp = top_B->data;
	top_B->data = top_B->next->data;
	top_B->next->data = tmp;
	add_command(2, "sb", cmd);
}

void	ss(t_deque *deq)
{
	int			tmp;
	t_cmd_deq	*cmd;
	t_list		*top;

	cmd = deq->cmd;
	top = deq->cursor->prev;
	tmp = top->data;
	top->data = top->prev->data;
	top->prev->data = tmp;
	top = deq->cursor;
	tmp = top->data;
	top->data = top->next->data;
	top->next->data = tmp;
	add_command(2, "ss", cmd);
}

void	pa(t_deque *deq)
{
	t_cmd_deq	*cmd;

	if (deq->cursor->end_flag == 1)
		return ;
	cmd = deq->cmd;
	deq->cursor = deq->cursor->next;
	deq->size_a++;
	deq->size_b--;
	add_command(2, "pa", cmd);
}

void	pb(t_deque *deq)
{
	t_cmd_deq	*cmd;

	if (deq->cursor == deq->end_A)
		return ;
	cmd = deq->cmd;
	deq->cursor = deq->cursor->prev;
	if (deq->end_B->end_flag == TRUE)
		deq->end_B = deq->end_B->prev;
	deq->size_a--;
	deq->size_b++;
	add_command(2, "pb", cmd);
}
