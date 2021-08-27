#include "push_swap.h"

void	error(char *str)
{
	ft_putstr("\033[1;31m", STDERR_FILENO);
	ft_putendl(str, STDERR_FILENO);
	ft_putstr("\033[0;0m", STDERR_FILENO);
	exit(1);
}

void	merror(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putendl("\033[1;31mMalloc error!", STDERR_FILENO);
		ft_putstr("\033[0;0m", STDERR_FILENO);
		exit(2);
	}
}

void	input_error(void)
{
	error("Input error");
}

void	print_deq(t_deque *deq)
{
	t_list	*tp_A;
	t_list	*tp_B;

	tp_A = deq->cursor->prev;
	tp_B = deq->cursor;
	printf("========================\n");
	printf("      Stack State!\n");
	printf("========================\n");
	printf("Size_all : %3d\nSize_A   : %3d\nSize_B   : %3d\n", deq->size, deq->size_a, deq->size_b);
	printf("========================\n");
	while (tp_A != NULL || tp_B->end_flag != 1)
	{
		if (tp_A != NULL && tp_B->end_flag != 1)
			printf("%11d | %11d\n", tp_A->data, tp_B->data);
		else if (tp_A == NULL && tp_B->end_flag != 1)
			printf("%11c | %11d\n", ' ', tp_B->data);
		else
			printf("%11d | %11c\n", tp_A->data, ' ');
		if (tp_A != NULL)
			tp_A = tp_A->prev;
		if (tp_B->end_flag != 1)
			tp_B = tp_B->next;
	}
	printf(" ---------     --------- \n");
	printf(" [Stack A]  |  [Stack B] \n");
}
