/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:19 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 22:11:17 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	rra_bns(t_deque *deq)
{
	t_list	*next;
	t_list	*pre;
	t_list	*tmp;
	t_list	*del;

	if (deq->size_a <= 1)
		return ;
	next = deq->cursor;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = deq->end_A->data;
	del = deq->end_A;
	deq->end_A = deq->end_A->next;
	link_node(tmp, next);
	link_node(pre, tmp);
	remove_node(del);
}

void	rrb_bns(t_deque *deq)
{
	t_list	*next;
	t_list	*pre;
	t_list	*tmp;
	t_list	*del;

	if (deq->size_b <= 1)
		return ;
	next = deq->cursor;
	pre = deq->cursor->prev;
	tmp = create_node();
	tmp->data = deq->end_B->data;
	del = deq->end_B;
	deq->end_B = deq->end_B->prev;
	link_node(tmp, next);
	link_node(pre, tmp);
	deq->cursor = deq->cursor->prev;
	remove_node(del);
}

void	rrr_bns(t_deque *deq)
{
	rra_bns(deq);
	rrb_bns(deq);
}
