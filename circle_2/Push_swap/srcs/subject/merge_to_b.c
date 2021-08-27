#include "push_swap.h"

static void	merge_b_ascend(t_deque *deq, int *n, int *len)
{
	if (len[LEFT] == 0)
		n[LEFT] = INT_MIN;
	if (len[MID] == 0)
		n[MID] = INT_MIN;
	if (len[RIGHT] == 0)
		n[RIGHT] = INT_MIN;
	if (len[LEFT] && (n[LEFT] == find_max(n[LEFT], n[MID], n[RIGHT])))
	{
		rra(deq);
		pb(deq);
		len[LEFT]--;
	}
	else if (len[MID] && (n[MID] == find_max(n[LEFT], n[MID], n[RIGHT])))
	{
		pb(deq);
		len[MID]--;
	}
	else
	{
		rrb(deq);
		len[RIGHT]--;
	}
}

static void	merge_b_descend(t_deque *deq, int *n, int *len)
{
	if (len[LEFT] == 0)
		n[LEFT] = INT_MAX;
	if (len[MID] == 0)
		n[MID] = INT_MAX;
	if (len[RIGHT] == 0)
		n[RIGHT] = INT_MAX;
	if (len[LEFT] && (n[LEFT] == find_min(n[LEFT], n[MID], n[RIGHT])))
	{
		rra(deq);
		pb(deq);
		len[LEFT]--;
	}
	else if (len[MID] && (n[MID] == find_min(n[LEFT], n[MID], n[RIGHT])))
	{
		pb(deq);
		len[MID]--;
	}
	else
	{
		rrb(deq);
		len[RIGHT]--;
	}
}

void	merge_to_b(t_deque *deq, int *len, int order)
{
	int	n[3];

	swap_number(&len[MID], &len[LEFT]);//가독성을 위해 위치 변경
	while (len[RIGHT] || len[MID] || len[LEFT])
	{
		n[LEFT] = deq->end_A->data;
		n[MID] = deq->cursor->prev->data;
		n[RIGHT] = deq->end_B->data;
		if (order == ASCEND)
			merge_b_ascend(deq, n, len);
		else
			merge_b_descend(deq, n, len);
	}
}
