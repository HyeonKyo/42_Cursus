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
	write(STDOUT_FILENO, "\t", 1);
}

static void	all_is_full(void)
{
	ft_putstr("\033[1;33m", STDOUT_FILENO);
	ft_putendl("\nEvery is finishing dinner!!\n\033[0;0m", STDOUT_FILENO);
}

int	state_message(t_philo *philo, t_cond cond)
{
	pthread_mutex_lock(&(philo->inf->pt_mtx));
	if (cond == FULL)
	{
		all_is_full();
		pthread_mutex_unlock(&(philo->inf->pt_mtx));
		return (TRUE);
	}
	if (check_condition(philo->inf))
	{
		pthread_mutex_unlock(&(philo->inf->pt_mtx));
		return (TRUE);
	}
	print_ms_time(philo);
	print_philo_nbr(philo);
	if (print_state(cond))
	{
		philo->inf->cond = DEAD;
		usleep(DELTA);
		pthread_mutex_unlock(&(philo->inf->pt_mtx));
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->inf->pt_mtx));
	return (FALSE);
}
