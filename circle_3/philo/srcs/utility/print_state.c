#include "philo.h"

int	print_state(t_cond cond)
{
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
	else if (cond == DEAD)
	{
		ft_putstr("\033[1;31m", STDOUT_FILENO);
		ft_putendl("died", STDOUT_FILENO);
		//usleep(100000);//unlock대기를 하면서 다른 메시지 출력을 막음.
		return (1);
	}
	return (0);
}
