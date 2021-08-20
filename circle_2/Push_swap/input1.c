#include "ft_utils.h"
#include "ft_type.h"
#include "list.h"

void	vaild_input(char *argv)
{
	int	i;
	int	fg;

	i = -1;
	fg = 0;
	while (argv[++i])
	{
		if (ft_isdigit(argv[i]) || argv[i] == ' ')
		{
			if (ft_isdigit(argv[i]))
				fg = 1;
		}
		else if (argv[i] == '-' || argv[i] == '+')
		{
			if (!ft_isdigit(argv[++i]))
				error();
			else
				fg = 1;
		}
		else
			error();
	}
	if (fg == 0)
		error();
}

void	check_valid_argv(int ac, char **argv)
{
	int	i;

	i = 0;
	while (++i < ac)
		vaild_input(argv[i]);
}

char	*merge_input(int ac, char **av)
{
/*
1. strjoin 반복으로 자동 할당 하면서 합쳐줌
3. 만약 문제가 있으면(말락실패) 리턴 0
4. 문제 없으면 합친 문자열 리턴
*/
	int		i;
	char	*str;
	char	*tmp;

	if (ac == 2)
		return (ft_strdup(av[1]));
	i = 2;
	str = ft_strjoin(av[1], av[2]);
	while (++i < ac)
	{
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, av[i]);
		if (tmp)
			free(tmp);
		if (str == 0)
			merror();
	}
	return (str);
}

unsigned int	absol(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	ps_atoi(int *idx, int sign, char *str, t_deque *deq)
{
	long long	num;
	int			digit_len;

	num = 0;
	digit_len = 0;
	if (str[*idx] == 0)
		error();
	while (ft_isdigit(str[*idx]))
	{
		digit_len++;
		num = num * 10 + (absol(str[(*idx)++]) - '0');
	}
	num = num * sign;
	if (digit_len > 10 || num < INT_MIN || num > INT_MAX)
		error();
	fillin_deque(deq, (int)num);
}
