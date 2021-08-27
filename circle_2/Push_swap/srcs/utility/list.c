/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:43 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 20:32:19 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(void)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	merror(lst);
	ft_memset(lst, 0, sizeof(t_list));
	return (lst);
}

void	link_node(t_list *n1, t_list *n2)
{
	if (n1 == NULL && n2 == NULL)
		return ;
	if (n1 != NULL)
		n1->next = n2;
	if (n2 != NULL)
		n2->prev = n1;
}

t_deque	*create_deque(void)
{
	t_deque	*deq;

	deq = (t_deque *)malloc(sizeof(t_deque));
	merror(deq);
	ft_memset(deq, 0, sizeof(t_deque));
	deq->end_node = create_node();
	deq->end_node->end_flag = 1;
	deq->end_B = deq->end_node;
	deq->cursor = deq->end_node;
	deq->end_A = deq->cursor;
	deq->cmd = create_cmd_deque();
	return (deq);
}

void	fillin_deque(t_deque *deq, int num)
{
	t_list	*tmp;

	tmp = create_node();
	tmp->data = num;
	link_node(tmp, deq->end_A);
	deq->end_A = tmp;
	deq->size++;
}

void	clear_deque(t_deque *deq)
{
	t_list	*cur;
	t_list	*tmp;

	cur = deq->end_A;
	while (cur)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
		tmp = 0;
	}
	clear_cmd_deq(deq->cmd);
	free(deq);
}

void	remove_node(t_list *cur)
{
	t_list	*next;
	t_list	*pre;

	if (cur == NULL)
		return ;
	next = cur->next;
	pre = cur->prev;
	link_node(pre, next);
	free(cur);
}
