#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	real_three_number_sort(t_deque *deq_A, t_cmd_deq *cmd_list)
{
	//deq_A에 숫자 딱 3개 있는 경우
	int	arr[3];

	arr[0] = deq_A->top->data;
	arr[1] = deq_A->top->next->data;
	arr[2] = deq_A->bot->data;
	if (arr[0] == find_max(3, arr))
		ra(deq_A, cmd_list);
	else if (arr[1] == find_max(3, arr))
		rra(deq_A, cmd_list);
	if (deq_A->top->data > deq_A->top->next->data)
		sa(deq_A, cmd_list);
}

void	other_three_number_sort(t_deque *deq_A, t_cmd_deq *cmd_list)
{
	if (deq_A->top->data > deq_A->top->next->data)
		sa(deq_A, cmd_list);
	if (check_already_sorted(deq_A))
		return ;
	ra(deq_A, cmd_list);
	if (deq_A->top->data > deq_A->top->next->data)
		sa(deq_A, cmd_list);
	if (check_already_sorted(deq_A))
		return ;
	rra(deq_A, cmd_list);
	if (deq_A->top->data > deq_A->top->next->data)
		sa(deq_A, cmd_list);
}

void	insert_four_number(t_deque *deq_A, int *arr, int *max, int *min)
{
	arr[0] = deq_A->top->data;
	arr[1] = deq_A->top->next->data;
	arr[2] = deq_A->top->next->next->data;
	arr[3] = deq_A->top->next->next->next->data;
	*max = find_max(4, arr);
	*min = find_min(4, arr);
}

void	real_four_number_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd)
{
	int	arr[4];
	int	max;
	int	min;

	insert_four_number(deq_A, arr, &max, &min);
	if (arr[0] == max)
		ra(deq_A, cmd);
	else if (arr[1] == max)
	{
		pb(deq_A, deq_B, cmd);
		ra(deq_A, cmd);
		pa(deq_A, deq_B, cmd);
	}
	else if (arr[2] == max)
		rra(deq_A, cmd);
	other_three_number_sort(deq_A, cmd);
	//max값을 스택 맨 뒤로 보내고 3개 정렬 수행
}

void	other_four_number_sort(t_deque *deq_A, t_deque *deq_B, t_cmd_deq *cmd)
{
	int	arr[4];
	int	max;
	int	min;

	insert_four_number(deq_A, arr, &max, &min);
	if (arr[0] == max)
	{
		ra(deq_A, cmd);
		pb(deq_A, deq_B, cmd);
		pb(deq_A, deq_B, cmd);
		rra(deq_A, cmd);
		sa(deq_A, cmd);
		pa(deq_A, deq_B, cmd);
		if (arr[3] < arr[2])
			sa(deq_A, cmd);
		pa(deq_A, deq_B, cmd);
	}
	else if (arr[1] == max)
	{
		pb(deq_A, deq_B, cmd);
		ra(deq_A, cmd);
		pb(deq_A, deq_B, cmd);
		rra(deq_A, cmd);
		sa(deq_A, cmd);
		pa(deq_A, deq_B, cmd);
		if (arr[3] < arr[2])
			sa(deq_A, cmd);
		pa(deq_A, deq_B, cmd);
	}
	else if (arr[2] == max)
	{
		ra(deq_A, cmd);
		ra(deq_A, cmd);
		sa(deq_A, cmd);
		rra(deq_A, cmd);
		rra(deq_A, cmd);
	}
	other_three_number_sort(deq_A, cmd);
}