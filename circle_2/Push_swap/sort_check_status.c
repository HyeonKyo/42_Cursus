#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

int		check_already_sorted(t_deque *deq)
{
	t_list	*cur;

	if (deq == 0)
		return (0);
	cur = deq->top;
	while (cur->next)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	return (1);//정렬되있는 상태
}

int		check_reverse_sorted(t_deque *deq, int len)
{
	//deq의 top부터 len만큼 역순인지 아닌지/ 역순이면 return 1
	int		i;
	int		check_num;
	t_list	*cur;

	if (deq->size > len)
		return (0);
	cur = deq->top;
	check_num = cur->data;
	i = -1;
	while (++i < len - 1)
	{
		if (check_num < cur->next->data)
			return (0);
		check_num = cur->next->data;
		cur = cur->next;
	}
	return (1);
}