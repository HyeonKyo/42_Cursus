/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:00 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:09 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"

void	ra_bns(t_deque *deq_A)
{
	t_list	*cur;

	cur = create_list();
	deq_A->bot->next = cur;
	cur->prev = deq_A->bot;
	cur->data = deq_A->top->data;
	del_top_node(deq_A);
	deq_A->bot = cur;
}

void	rb_bns(t_deque *deq_B)
{
	t_list	*cur;

	cur = create_list();
	deq_B->bot->next = cur;
	cur->prev = deq_B->bot;
	cur->data = deq_B->top->data;
	del_top_node(deq_B);
	deq_B->bot = cur;
}

void	rr_bns(t_deque *deq_A, t_deque *deq_B)
{
	t_list	*cur;

	cur = create_list();
	deq_A->bot->next = cur;
	cur->prev = deq_A->bot;
	cur->data = deq_A->top->data;
	del_top_node(deq_A);
	deq_A->bot = cur;
	cur = 0;
	cur = create_list();
	deq_B->bot->next = cur;
	cur->prev = deq_B->bot;
	cur->data = deq_B->top->data;
	del_top_node(deq_B);
	deq_B->bot = cur;
}
	
