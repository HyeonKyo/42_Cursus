#include "philo.h"

void	print_ms_time(t_philo *philo)
{
	long long	cur;

	save_time(&cur);
	ft_putnbr(cur - philo->inf->begin, STDOUT_FILENO);
	ft_putstr("ms\t", STDOUT_FILENO);
}

void	print_philo_nbr(t_philo *philo)
{
	ft_putnbr(philo->num, STDOUT_FILENO);
	ft_putstr(" ", STDOUT_FILENO);
}

void	all_is_full(void)
{
	ft_putstr("\033[1;33m", STDOUT_FILENO);
	ft_putendl("\nEvery is finishing dinner!!\n\033[0;0m", STDOUT_FILENO);
	exit(0);
}

void	state_message(t_philo *philo)
{
	pthread_mutex_lock(&(philo->inf->pt_mtx));
	if (philo->cond == FULL)
		all_is_full();
	print_ms_time(philo);
	print_philo_nbr(philo);
	print_state(philo);
	pthread_mutex_unlock(&(philo->inf->pt_mtx));
}
