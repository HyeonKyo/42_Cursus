#include "philo_bonus.h"

void	print_ms_time(t_philo *philo)
{
	long long	cur;

	save_time(&cur);
	ft_putnbr(cur - philo->begin, STDOUT_FILENO);
	ft_putstr("ms\t", STDOUT_FILENO);
}

void	print_philo_nbr(t_philo *philo)
{
	ft_putnbr(philo->num, STDOUT_FILENO);
	write(STDOUT_FILENO, "\t", 1);
}

static void	all_is_full(void)
{
	ft_putstr("\033[1;33m", STDOUT_FILENO);
	ft_putendl("\nEvery is finishing dinner!!\n\033[0;0m", STDOUT_FILENO);
}

void	state_message(t_philo *philo, t_cond cond)
{
	sem_wait(philo->sem.print);
	if (cond == FULL)
	{
		all_is_full();
		return ;
	}
	print_ms_time(philo);
	print_philo_nbr(philo);
	if (print_state(cond))
		return ;
	else
		sem_post(philo->sem.print);
}
