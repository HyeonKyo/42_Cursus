#include "push_swap.h"

static void	repeat_rr(t_deque *deq, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		rr(deq);
}

void	sort_skip(t_deque *deq, int size, int order)
{
	int	len[3];

	if (size <= 3)
	{
		except_sort_skip(deq, size, order);
		return ;
	}
	len[RIGHT] = size / 3;
	len[MID] = size / 3;
	len[LEFT] = size / 3 + size % 3;
	sort_skip(deq, len[RIGHT], order);
	sort_fix(deq, len[MID], !order);
	repeat_rr(deq, len[MID]);
	sort_fix(deq, len[LEFT], order);
	merge_to_b(deq, len, order);
}

void	sort_fix(t_deque *deq, int size, int order)
{
	int	len[3];

	if (size <= 3)
	{
		except_sort_fix(deq, size, order);
		return ;
	}
	len[RIGHT] = size / 3 + size % 3;
	len[MID] = size / 3;
	len[LEFT] = size / 3;
	sort_skip(deq, len[RIGHT], order);
	sort_skip(deq, len[MID], !order);
	sort_fix(deq, len[LEFT], order);
	repeat_rr(deq, len[MID]);
	merge_to_a(deq, len, order);
}

void	sort(t_deque *deq)
{
	int	len[3];

	if (check_already_sorted(deq, deq->size, DESCEND))
		return ;
	if (deq->size == 2)
		return (sa(deq));
	else if (deq->size == 3)
		return (except_sort_fix(deq, 3, DESCEND));
	len[LEFT] = deq->size / 3;
	len[MID] = deq->size / 3;
	len[RIGHT] = deq->size / 3 + deq->size % 3;
	sort_skip(deq, len[RIGHT], ASCEND);
	sort_skip(deq, len[MID], DESCEND);
	sort_fix(deq, len[LEFT], DESCEND);
	merge_to_a(deq, len, DESCEND);
}
