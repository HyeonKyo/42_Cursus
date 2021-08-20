#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	push_queue(t_ll num, t_queue *queue[10], int q_num)
{
	t_qu_lst	*cur;

	if (queue[q_num] == 0)
		make_queue(queue, q_num);
	else
	{
		cur = (t_qu_lst *)malloc(sizeof(t_qu_lst));
		ft_memset(cur, 0, sizeof(t_qu_lst));
		queue[q_num]->last->next = cur;
		queue[q_num]->last = queue[q_num]->last->next;
	}
	queue[q_num]->last->data = num;
	queue[q_num]->size++;
}

void	putin_data_in_array(t_deque *deq, t_sort *repo, t_ll bios)
{
	int	i;
	t_list	*cur;

	i = 0;
	cur = deq->top;
	while (i < repo->size)
	{
		repo->arr[i++] = cur->data + bios;
		cur = cur->next;
	}
}

void	pull_queue(t_sort *repo, t_queue *queue[10])
{
	int	i;
	int	j;
	t_qu_lst	*cur;

	i = -1;
	j = 0;
	while (++i < 10)
	{
		if (queue[i] == 0)
			continue ;
		cur = queue[i]->fst;
		while (cur)
		{
			repo->arr[j++] = cur->data;
			cur = cur->next;
		}
	}
}

void	clear_queue(t_queue *queue[10])
{
	int	i;
	t_qu_lst	*cur;
	t_qu_lst	*tmp;

	i = -1;
	while (++i < 10)
	{
		if (queue[i] == 0)
			continue ;
		cur = queue[i]->fst;
		while (cur)
		{
			tmp = cur->next;
			free(cur);
			cur = tmp;
		}
		free(queue[i]);
		queue[i] = 0;
	}
}

void	pre_sorting(t_sort *repo, int dg)
{
	int	i;
	int	last;
	static t_queue	*queue[10];

	i = -1;
	while (++i < repo->size)
	{
		last = last_digit_num(repo->arr[i], dg);
		push_queue(repo->arr[i], queue, last);
	}
	pull_queue(repo, queue);
	clear_queue(queue);
}
