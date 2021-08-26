#include "push_swap.h"

static void	ps_atoi(int *idx, int sign, char *str, t_deque *deq)
{
	long long	num;
	int			digit_len;

	num = 0;
	digit_len = 0;
	while (ft_isdigit(str[*idx]))
	{
		digit_len++;
		num = num * 10 + (ft_absol(str[(*idx)++]) - '0');
	}
	num = num * sign;
	if (digit_len > 10 || num < INT_MIN || num > INT_MAX)
		error("Input number out of range!");
	fillin_deque(deq, (int)num);
}

static t_deque	*insert_data(char *str)
{
	int		i;
	int		sign;
	t_deque	*deq;

	i = 0;
	deq = create_deque();
	merror(deq);
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
	deq->size_a = deq->size;
	free(str);
	return (deq);
}

static t_deque	*check_duplicated_num(char *str)
{
	int		ck_num;
	t_list	*cur;
	t_list	*tmp;
	t_deque	*deq;

	deq = insert_data(str);
	cur = deq->end_A;
	while (!cur->end_flag)
	{
		ck_num = cur->data;
		tmp = cur->next;
		while (tmp)
		{
			if (!tmp->end_flag && (tmp->data == ck_num))//겹치는 숫자
				error("Duplicated numbers");
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	return (deq);
}

t_deque	*make_stack(int ac, char **av)
{
	char	*str;
	t_deque	*deq;

	check_valid_argv(ac, av);
	str = merge_input(ac, av);
	deq = check_duplicated_num(str);
	return (deq);
}
