#include "philo_bonus.h"

void	error(char *str)
{
	ft_putendl(str, STDERR_FILENO);
	exit(1);
}

void	merror(void *ret)
{
	if (ret == 0)
		error("Malloc error!");
}

static void	usage(void)
{
	ft_putstr("\033[1;37m", STDERR_FILENO);
	ft_putstr("\nUsage : ./philo [number of philo] ", STDERR_FILENO);
	ft_putstr("[time to die] [time to eat] ", STDERR_FILENO);
	ft_putendl("[time to sleep]", STDERR_FILENO);
	ft_putstr("([number_of_times_each", STDERR_FILENO);
	ft_putendl("_philosopher_must_eat])\n", STDERR_FILENO);
}

void	input_error(void)
{
	ft_putstr("\033[1;31m", STDERR_FILENO);
	ft_putendl("\nInput Error!", STDERR_FILENO);
	usage();
	exit(1);
}
