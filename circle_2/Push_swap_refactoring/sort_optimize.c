#include "push_swap.h"

void	insert_four_number(t_deque *deq_A, int *arr, int *max, int *min)
{
	arr[0] = deq_A->end_A->data;
	arr[1] = deq_A->end_A->next->data;
	arr[2] = deq_A->end_A->next->next->data;
	arr[3] = deq_A->end_A->next->next->next->data;
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
		ra(deq_A);
	else if (arr[1] == max)
	{
		pb(deq_A, deq_B);
		ra(deq_A);
		pa(deq_A, deq_B);
	}
	else if (arr[2] == max)
		rra(deq_A);
	usual_three_sort_fix(deq_A);
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
		ra(deq_A);
		pb(deq_A, deq_B);
		pb(deq_A, deq_B);
		rra(deq_A);
		sa(deq_A);
		pa(deq_A, deq_B);
		if (arr[3] < arr[2])
			sa(deq_A);
		pa(deq_A, deq_B);
	}
	else if (arr[1] == max)
	{
		pb(deq_A, deq_B);
		ra(deq_A);
		pb(deq_A, deq_B);
		rra(deq_A);
		sa(deq_A);
		pa(deq_A, deq_B);
		if (arr[3] < arr[2])
			sa(deq_A);
		pa(deq_A, deq_B);
	}
	else if (arr[2] == max)
	{
		ra(deq_A);
		ra(deq_A);
		sa(deq_A);
		rra(deq_A);
		rra(deq_A);
	}
	usual_three_sort_fix(deq_A);
}
