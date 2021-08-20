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

int	ra(t_deque *deq_A, t_cmd_deq *cmd_list)
{
	t_list	*cur;

	cur = create_list();
	deq_A->bot->next = cur;
	cur->prev = deq_A->bot;
	cur->data = deq_A->top->data;
	del_top_node(deq_A);
	deq_A->bot = cur;
	add_command(2, "ra", cmd_list);
	return (1);
}

int	rb(t_deque *deq_B, t_cmd_deq *cmd_list)
{
	t_list	*cur;

	cur = create_list();
	deq_B->bot->next = cur;
	cur->prev = deq_B->bot;
	cur->data = deq_B->top->data;
	del_top_node(deq_B);
	deq_B->bot = cur;
	add_command(2, "rb", cmd_list);
	return (1);
}

void	rr(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd_list)
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
	add_command(2, "rr", cmd_list);
}
	
