/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:00 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 22:57:47 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ra_bns(t_deque *deq)
{
	t_list	*tmp;
	t_list	*del;

	if (deq->size_a <= 1)
		return ;
	tmp = create_node();
	tmp->data = deq->cursor->prev->data;
	del = deq->cursor->prev;
	link_node(tmp, deq->end_A);
	deq->end_A = deq->end_A->prev;
	remove_node(del);
}

void	rb_bns(t_deque *deq)
{
	t_list	*tmp;
	t_list	*del;

	if (deq->size_b <= 1)
		return ;
	tmp = create_node();
	tmp->data = deq->cursor->data;
	del = deq->cursor;
	deq->cursor = deq->cursor->next;
	link_node(deq->end_B, tmp);
	link_node(tmp, deq->end_node);
	remove_node(del);
}

void	rr_bns(t_deque *deq)
{
	ra_bns(deq);
	rb_bns(deq);
}
