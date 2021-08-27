#include "push_swap.h"

static void	only_three_sort(t_deque *deq, int order)
{
	int			top;
	int			mid;
	int			bot;

	top = deq->cursor->prev->data;
	mid = deq->end_A->next->data;
	bot = deq->end_A->data;
	if (order == ASCEND)
	{
		if (top == find_min(top, mid, bot))
			ra(deq);
		else if (mid == find_min(top, mid, bot))
			rra(deq);
	}
	else
	{
		if (top == find_max(top, mid, bot))
			ra(deq);
		else if (mid == find_max(top, mid, bot))
			rra(deq);
	}
	top = deq->cursor->prev->data;
	mid = deq->end_A->next->data;
	if ((mid > top) == order)
		sa(deq);
}

static void	usual_three_sort_fix(t_deque *deq, int order)
{
	t_list	*cur;

	cur = deq->cursor;
	if ((cur->prev->data > cur->prev->prev->data) == order)
		sa(deq);
	if (check_already_sorted(deq, 3, order))
		return ;
	ra(deq);
	if ((cur->prev->data > cur->prev->prev->data) == order)
		sa(deq);
	if (check_already_sorted(deq, 3, order))
		return ;
	rra(deq);
	if ((cur->prev->data > cur->prev->prev->data) == order)
		sa(deq);
}

static void	usual_three_sort_skip(t_deque *deq, int order)
{
	t_list	*cur;

	cur = deq->cursor;
	if ((cur->prev->prev->data < cur->prev->data) != order)
		sa(deq);
	pb(deq);
	cur = deq->cursor;
	if ((cur->prev->prev->data < cur->prev->data) != order)
		sa(deq);
	pb(deq);
	cur = deq->cursor;
	if ((cur->data < cur->next->data) != order)
		sb(deq);
	pb(deq);
}

void	except_sort_fix(t_deque *deq, int size, int order)
{
	t_list	*cur;

	cur = deq->cursor;
	if (size <= 1)
		return ;
	else if (size == 2)
	{
		if ((cur->prev->data > cur->prev->prev->data) != order)
			sa(deq);
	}
	else
	{
		if (deq->size_a == 3)
			only_three_sort(deq, order);
		else
			usual_three_sort_fix(deq, order);
			//size는 3이 주어졌지만 실제 stack_a엔 3만큼 있지 않을 때 오류
	}
}

void	except_sort_skip(t_deque *deq, int size, int order)
{
	t_list	*cur;

	cur = deq->cursor;
	if (size == 0)
		return ;
	if (size == 3)
	{
		usual_three_sort_skip(deq, order);
		return ;
	}
	else if (size == 2)
	{
		if ((cur->prev->prev->data < cur->prev->data) != order)
			sa(deq);
		pb(deq);
	}
	pb(deq);
}
