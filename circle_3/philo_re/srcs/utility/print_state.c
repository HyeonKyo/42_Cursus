#include "philo.h"

static void	print_dead(void)
{
	ft_putstr("\033[1;31m", STDOUT_FILENO);
	ft_putendl("died", STDOUT_FILENO);
	//system("leaks philo > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	//지우기
	exit(0);
}

void	print_state(t_philo *philo)
{
	t_cond	cond;

	cond = philo->cond;
	if (cond == EATING)
	{
		ft_putstr("\033[1;37;42m", STDOUT_FILENO);
		ft_putendl("is eating\033[0;0m", STDOUT_FILENO);
	}
	else if (cond == THINKING)
	{
		ft_putendl("is thinking", STDOUT_FILENO);
	}
	else if (cond == SLEEPING)
	{
		ft_putendl("is sleeping", STDOUT_FILENO);
	}
	else if (cond == GRAB)
	{
		ft_putstr("\033[1;33m", STDOUT_FILENO);
		ft_putendl("has taken a fork\033[0;0m", STDOUT_FILENO);
	}
	else if (philo->cond == DEAD)
		print_dead();
}
