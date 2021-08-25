#include "push_swap.h"

static void	check_argv(char *argv)
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
				input_error();
			else
				fg = 1;
		}
		else
			input_error();
	}
	if (fg == 0)
		input_error();
}

void	check_valid_argv(int ac, char **argv)
{
	int	i;

	i = 0;
	while (++i < ac)
		check_argv(argv[i]);
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
		merror(str);
	}
	return (str);
}
