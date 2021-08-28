#include "minitalk.h"

void	error(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(1);
}

static void	usage(void)
{
	ft_putstr("Usage : ./client [Server's", STDERR_FILENO);
	ft_putendl(" pid] [\" Message \"]", STDERR_FILENO);
	ft_putendl("(Message's len is lower than INT_MAX)", STDERR_FILENO);
}

void	input_error(void)
{
	ft_putendl("\nInput Error!\n", STDERR_FILENO);
	usage();
	exit(1);
}

void	sigerror(void)
{
	error("\nSignal Error!");
}

