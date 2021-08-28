#include "push_swap.h"

void	fillin_deque(t_deque *deq, int num)
{
	t_list	*tmp;

	tmp = create_node();
	tmp->data = num;
	link_node(tmp, deq->end_A);
	deq->end_A = tmp;
	deq->size++;
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
