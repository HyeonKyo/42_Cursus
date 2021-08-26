/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:15 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 22:09:49 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	sa_bns(t_deque *deq)
{
	t_list	*cur;

	if (deq->size_a <= 1)
		return ;
	cur = deq->cursor;
	swap_number(&(cur->prev->data), &(cur->prev->prev->data));
}

void	sb_bns(t_deque *deq)
{
	t_list	*cur;

	if (deq->size_b <= 1)
		return ;
	cur = deq->cursor;
	swap_number(&(cur->data), &(cur->next->data));
}

void	ss_bns(t_deque *deq)
{
	sa_bns(deq);
	sb_bns(deq);
}

void	pa_bns(t_deque *deq)
{
	if (deq->size_b <= 0)
		return ;
	deq->cursor = deq->cursor->next;
	deq->size_b--;
	deq->size_a++;
	if (deq->size_b == 0)
		deq->end_B = deq->end_node;
}

void	pb_bns(t_deque *deq)
{
	if (deq->size_a <= 0)
		return ;
	deq->cursor = deq->cursor->prev;
	deq->size_a--;
	deq->size_b++;
	if (deq->size_a == 0)
		deq->end_A = NULL;
}
