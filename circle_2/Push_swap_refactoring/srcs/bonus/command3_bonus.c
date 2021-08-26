/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:19 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:20 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"

void	rra_bns(t_deque *deq_A)
{
	t_list	*cur;

	cur = create_list();
	deq_A->top->prev = cur;
	cur->next = deq_A->top;
	cur->data = deq_A->bot->data;
	del_bottom_node(deq_A);
	deq_A->top = cur;
}

void	rrb_bns(t_deque *deq_B)
{
	t_list	*cur;

	cur = create_list();
	deq_B->top->prev = cur;
	cur->next = deq_B->top;
	cur->data = deq_B->bot->data;
	del_bottom_node(deq_B);
	deq_B->top = cur;
}

void	rrr_bns(t_deque *deq_A, t_deque *deq_B)
{
	t_list	*cur;

	cur = create_list();
	deq_A->top->prev = cur;
	cur->next = deq_A->top;
	cur->data = deq_A->bot->data;
	del_bottom_node(deq_A);
	deq_A->top = cur;
	cur = 0;
	cur = create_list();
	deq_B->top->prev = cur;
	cur->next = deq_B->top;
	cur->data = deq_B->bot->data;
	del_bottom_node(deq_B);
	deq_B->top = cur;
}
