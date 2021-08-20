#include "ft_type.h"
#include "ft_utils.h"
#include "list.h"
#include "push_swap.h"

void	B_to_A(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	int	i;
	int	rb_cnt;

	i = -1;
	if (check_reverse_sorted(deq_B, len))
		while (++i < len)
			pa(deq_A, deq_B, info->cmd);
	else if (len <= 3)
	{
		while (++i < len)
			pa(deq_A, deq_B, info->cmd);
		except_sort(deq_A, deq_B, len, info->cmd);
	}
	else
	{
		pre_sort(deq_B, len, &(info->piv));
		divide_B(deq_A, deq_B, info, len);
		rb_cnt = info->cnt[1];
		A_to_B(deq_A, deq_B, info, info->cnt[2]);
		while (++i < rb_cnt)
			pa(deq_A, deq_B, info->cmd);
		A_to_B(deq_A, deq_B, info, rb_cnt);
	}
}

void	A_to_B(t_deque *deq_A, t_deque *deq_B, t_info *info, int len)
{
	//초기 len = deq_A->size, 이후 = ra_cnt
	int	big_B_to_A_cnt;
	int	sml_B_to_A_cnt;

	if (check_already_sorted(deq_A) || reverse_sort(deq_A, deq_B, info->cmd))
		deq_A->case_num = 3;
	else if (len <= 4)
	{
		except_sort(deq_A, deq_B, len, info->cmd);
		deq_A->case_num = 3;
	}
	else
	{
		pre_sort(deq_A, len, &(info->piv));
		//printf("big sml : %d %d\n", info->piv.big, info->piv.sml);
		divide_A(deq_A, deq_B, info, len); //ra rb pb카운트
		big_B_to_A_cnt = info->cnt[1];
		sml_B_to_A_cnt = info->cnt[3] - info->cnt[1];
		if (deq_A->case_num == 0)
		{
			swap_number(&big_B_to_A_cnt, &sml_B_to_A_cnt);
			deq_A->case_num = 1;
		}
		A_to_B(deq_A, deq_B, info, info->cnt[0]);
		B_to_A(deq_A, deq_B, info, big_B_to_A_cnt);
		B_to_A(deq_A, deq_B, info, sml_B_to_A_cnt);
	}
}

t_info	*q_sort(t_deque *deq_A, t_deque *deq_B)
{
	t_info	*info;

	if (check_already_sorted(deq_A))
		exit(0);
	setup_info(&info);
	A_to_B(deq_A, deq_B, info, deq_A->size);
	// if (check_already_sorted(deq_A))
	// 	printf("Success\n");
	// else
	// {
	// 	print_deq(deq_A, deq_B);
	// 	printf("deq size : %d\n", deq_A->size);
	// 	printf("cmd len : %d\n", info->cmd->size);
	// }
	clear_deque(deq_A);
	clear_deque(deq_B);
	return (info);
}

// A_to_B(stack_A, stack_B, info, base)
// {
// 	pb, rb_cnt, info에 cnt구조체 넣어줌.
// 	A스택 정렬 끝나면 재귀 종료
// 		=>정렬해야 할 숫자 개수가 3개 이하일 때(base_len함수 <= 3)
// 			=> 이거 어떻게?, a_to_b의 인자로 base를 넣음
// 			=> 맨 처음 a_to_b base는 stack_A의 bot값
// 		=>except_sort실행 후 return으로 재귀 종료
// 			=>except_sort는 그냥 a스택에 위의 3개 인자를 정렬
// 	정렬 => pb카운트 rb카운트 ra카운트
// 	rb, ra카운트 이용해서 rrr rra rrb적절히 사용
// 	다시 A_to_B
// 	B_to_A(pb, rb_cnt)
// 	{
// 		base는 A->top
// 		rbcnt만큼 3등분 -> 2블록 a로
// 		다시 a_to_b(pa_cnt, base)
// 		base는 A->top
// 		나머지 1/3 a로
// 		다시 a_to_b
// 	}
// 	B_to_A(pb, pb-rb_cnt);
// }
