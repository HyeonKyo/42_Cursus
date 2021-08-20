#include "philo.h"

void	print_ms_time(t_philo *philo)
{
	ft_putstr("\033[30;47m", STDOUT_FILENO);
	ft_putnbr(philo->tm_save - philo->inf->begin, STDOUT_FILENO);
	ft_putstr("\033[0;0m\t", STDOUT_FILENO);
}

void	print_philo_nbr(t_philo *philo)
{
	ft_putstr("\033[1;37m", STDOUT_FILENO);
	ft_putnbr(philo->num, STDOUT_FILENO);
	ft_putstr("\033[0;0m ", STDOUT_FILENO);
}

void	print_grab(void)
{
	ft_putstr("\033[1;33m", STDOUT_FILENO);
	ft_putendl("has taken a fork\033[0;0m", STDOUT_FILENO);
}

void	print_eat(void)
{
	ft_putstr("\033[1;34m", STDOUT_FILENO);
	ft_putendl("is eating", STDOUT_FILENO);
}

void	print_sleep(void)
{
	ft_putstr("\033[0;32m", STDOUT_FILENO);
	ft_putendl("is sleeping", STDOUT_FILENO);
}

void	print_think(void)
{
	ft_putstr("\033[0;36m", STDOUT_FILENO);
	ft_putendl("is thinking", STDOUT_FILENO);
}

void	print_dead(void)
{
	ft_putstr("\033[1;31m", STDOUT_FILENO);
	ft_putendl("died", STDOUT_FILENO);
	exit(0);
}

void	all_is_full(void)
{
	ft_putstr("\033[1;33m", STDOUT_FILENO);
	ft_putendl("\nEvery is finishing dinner!!\n\033[0;0m", STDOUT_FILENO);
	exit(0);
}

void	print_state(t_philo *philo)
{
	if (philo->cond == GRAB)
		print_grab();
	else if (philo->cond == EATING)
		print_eat();
	else if (philo->cond == SLEEPING)
		print_sleep();
	else if (philo->cond == THINKING)
		print_think();
	else if (philo->cond == DEAD)
		print_dead();
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
