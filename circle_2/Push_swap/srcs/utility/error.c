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
