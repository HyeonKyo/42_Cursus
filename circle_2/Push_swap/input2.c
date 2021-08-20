#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"
#include "push_swap.h"

t_deque	*insert_data(char *str)
{
	int		i;
	int		sign;
	t_deque	*deq;

	i = 0;
	deq = create_deque();
	if (deq == 0)
		merror();
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 0)
			break ;
		sign = 1;
		if (str[i] == '-' || str[i] == '+')
			if (str[i++] == '-')
				sign = -1;
		ps_atoi(&i, sign, str, deq);
	}
	free(str);
	return (deq);
}

t_deque	*check_duplicated_num(char *str)
{
	int		ck_num;
	t_list	*cur;
	t_list	*tmp;
	t_deque	*deq;

	deq = insert_data(str);
	cur = deq->top;
	while (cur)
	{
		ck_num = cur->data;
		tmp = cur->next;
		while (tmp)
		{
			if (tmp->data == ck_num)//겹치는 숫자
				error();
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (deq);
}

t_deque	*check_all_input(int ac, char **av)
{
	char	*str;
	t_deque	*deq;

	check_valid_argv(ac, av);
	str = merge_input(ac, av);
	deq = check_duplicated_num(str);
	return (deq);
}

t_deque	*make_stack(int ac, char **av, t_deque **deq_A)
{
	t_deque *deq_B;

	*deq_A = check_all_input(ac, av);
	deq_B = (t_deque *)malloc(sizeof(t_deque));
	ft_memset(deq_B, 0, sizeof(t_deque));
	return (deq_B);
}