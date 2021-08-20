#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

int		reverse_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd)
{
	int	i;
	int	len;

	len = deq_A->size;
	if (deq_A->case_num > 1 || len < 6 || !check_reverse_sorted(deq_A, len))
		return (0);
	i = -1;
	while (++i < len - 1)
	{
		rra(deq_A, cmd);
		pb(deq_A, deq_B, cmd);
	}
	i = -1;
	while (++i < len - 1)
		pa(deq_A, deq_B, cmd);
	if (deq_A->case_num == 1)
		deq_A->case_num = 3;
	return (1);
}

void	print_deq(t_deque *deq_A, t_deque *deq_B)
{
	t_list *cur;
	t_list *cur2;
	int		size;
	int		rest;

	cur = deq_A->top;
	cur2 = deq_B->top;
	size = deq_A->size;
	rest = absol(size - deq_B->size);
	if (deq_A->size > deq_B->size)
		size = deq_B->size;
	printf("----------deq----------\n");
	printf("deq_A size : %d, deq_B size : %d\n", deq_A->size, deq_B->size);
	while (size--)
	{
		printf("data : %11d  %11d\n", cur->data, cur2->data);
		cur = cur->next;
		cur2 = cur2->next;
		if (cur == 0 || cur2 == 0)
			break;
	}
	if (deq_A->size < deq_B->size)
	{
		while (rest--)
		{
			printf("data : '%10c' %11d\n", ' ', cur2->data);
			cur2 = cur2->next;
		}
	}
	else
	{
		while (rest--)
		{
			printf("data : %11d '%10c'\n", cur->data, ' ');
			cur = cur->next;
		}
	}
}

void	except_sort(t_deque *deq_A, t_deque *deq_B, int len, t_cmd_deq *cmd)
{
	if (check_already_sorted(deq_A) || len <= 1)
		return ;
	if (len == 2)
	{
		if (deq_A->top->data > deq_A->top->next->data)
			sa(deq_A, cmd);
	}
	else if (len == 3)
	{
		if (deq_A->case_num <= 1)
			real_three_number_sort(deq_A, cmd);
		else
			other_three_number_sort(deq_A, cmd);
	}
	else
	{
		if (deq_A->case_num <= 1)
			real_four_number_sort(deq_A, deq_B, cmd);
		else
			other_four_number_sort(deq_A, deq_B, cmd);
	}
}

void	reverse_stack(t_deque *deq_A, t_deque *deq_B, t_info *info)
{
	int	rest;
	int	com;
	int	i;

	if (deq_A->case_num == 1)
	{
		i = info->cnt[1];
		while (i--)
			rrb(deq_B, info->cmd);
	}
	else if (deq_A->case_num == 0)
		return ;
	else
	{
		rest = absol(info->cnt[0] - info->cnt[1]);
		com = small_num(info->cnt[0], info->cnt[1]);
		i = -1;
		while (++i < com)
			rrr(deq_A, deq_B, info->cmd);
		i = -1;
		if (info->cnt[0] >= info->cnt[1])
			while (++i < rest)
				rra(deq_A, info->cmd);
		else
			while (++i < rest)
				rrb(deq_B, info->cmd);
	}
}

void	divide_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	ft_memset(info->cnt, 0, sizeof(int) * 4);
	if (len <= 0)
		return ;
	while (len--)
	{
		if (deq_B->top->data < info->piv.sml)
			info->cnt[1] += rb(deq_B, info->cmd);
		else
		{
			info->cnt[2] += pa(deq_A, deq_B, info->cmd);
			if (deq_A->top->data <= info->piv.big)
				info->cnt[0] += ra(deq_A, info->cmd);
		}
	}
	reverse_stack(deq_A, deq_B, info);
}

void	divide_A(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	ft_memset(info->cnt, 0, sizeof(int) * 4);
	while (len--)
	{
		if (deq_A->top->data >= info->piv.big)
			info->cnt[0] += ra(deq_A, info->cmd);
		else
		{
			info->cnt[3] += pb(deq_A, deq_B, info->cmd);
			if (deq_A->case_num == 0)//맨처음은 rrb를 안쓸 수 있음
			{
				if (deq_B->top->data < info->piv.sml)
					info->cnt[1] += rb(deq_B, info->cmd);
			}
			else
				if (deq_B->top->data >= info->piv.sml)//6보다 작으면 그냥 넘겨주기만 함, 왜? && n > 6
					info->cnt[1] += rb(deq_B, info->cmd);
		}
	}
	reverse_stack(deq_A, deq_B, info);
	//cnt[0] = ra
	//cnt[1] = rb
	//cnt[2] = pa
	//cnt[3] = pb
}