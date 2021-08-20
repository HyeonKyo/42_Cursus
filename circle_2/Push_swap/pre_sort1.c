#include "ft_type.h"
#include "ft_utils.h"

void	search_stack(t_deque *deq, int len, int *max, int *min)
{
	t_list	*cur;

	*max = INT_MIN;
	*min = INT_MAX;
	cur = deq->top;
	while (len--)
	{
		if (cur->data > *max)
			*max = cur->data;
		if (cur->data < *min)
			*min = cur->data;
		cur = cur->next;
	}
}

t_sort	*make_repository(int len)
{
	t_sort	*repo;

	repo = (t_sort *)malloc(sizeof(t_sort) * 1);
	if (repo == 0)
		merror();
	repo->arr = (long long *)malloc(sizeof(long long) * len);
	if (repo->arr == 0)
		merror();
	repo->size = len;
	return (repo);
}

int		find_digit_len(t_ll num)
{
	int	digit;

	digit = 0;
	while (num > 0)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

int		last_digit_num(long long n, int dg)
{
	int	i;

	i = 0;
	while (++i < dg)
		n /= 10;
	return ((int)(n % 10));
}

void	make_queue(t_queue *queue[10], int idx)
{
	queue[idx] = (t_queue *)malloc(sizeof(t_queue));
	queue[idx]->fst = (t_qu_lst *)malloc(sizeof(t_qu_lst));
	queue[idx]->last = queue[idx]->fst;
	queue[idx]->size = 0; 
	ft_memset(queue[idx]->fst, 0, sizeof(t_qu_lst));
}
