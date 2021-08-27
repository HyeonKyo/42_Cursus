#include "push_swap.h"

void	merge_a_ascend(t_deque *deq, int *n, int *len)
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
		len[LEFT]--;
	}
	else if (len[MID] && (n[MID] == find_min(n[LEFT], n[MID], n[RIGHT])))
	{
		pa(deq);
		len[MID]--;
	}
	else
	{
		rrb(deq);
		pa(deq);
		len[RIGHT]--;
	}
}

void	merge_a_descend(t_deque *deq, int *n, int *len)
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
		len[LEFT]--;
	}
	else if (len[MID] && (n[MID] == find_max(n[LEFT], n[MID], n[RIGHT])))
	{
		pa(deq);
		len[MID]--;
	}
	else
	{
		rrb(deq);
		pa(deq);
		len[RIGHT]--;
	}
}

void	merge_to_a(t_deque *deq, int *len, int order)
{
	int	n[3];

	if (deq->size_a != len[LEFT])//sort함수의 merge_to_a인 경우만 이 if문이 실행 안됨.(가독성을 위해 이 swap을 많이 실행함.)
		swap_number(&len[MID], &len[RIGHT]);
	while (len[RIGHT] || len[MID] || len[LEFT])
	{
		n[LEFT] = deq->end_A->data;
		n[MID] = deq->cursor->data;
		n[RIGHT] = deq->end_B->data;
		if (order == ASCEND)
			merge_a_ascend(deq, n, len);
		else
			merge_a_descend(deq, n, len);
	}
}
