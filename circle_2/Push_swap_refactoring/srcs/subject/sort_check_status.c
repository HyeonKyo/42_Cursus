#include "push_swap.h"

int		check_already_sorted(t_deque *deq, int size, int order)
{
	t_list	*cur;

	if (deq == 0)
		return (0);
	cur = deq->cursor->prev;
	while (cur && size--)
	{
		if ((cur->prev->data < cur->data) != order)
			return (0);
		cur = cur->prev;
	}
	return (1);//정렬되있는 상태
}
