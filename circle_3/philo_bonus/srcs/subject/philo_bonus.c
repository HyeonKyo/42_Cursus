/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:35:49 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:35:50 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	save_arg(int ac, char **av, t_philo *philo)
{
	if (!(ft_atoi(av[1], &(philo->n_philo)) && ft_atoi(av[2], &(philo->tm_die))
			&& ft_atoi(av[3], &(philo->tm_eat))
			&& ft_atoi(av[4], &(philo->tm_sleep))))
		return (ERROR);
	if (ac == 6)
	{
		if (!ft_atoi(av[5], &(philo->n_must)))
			return (ERROR);
	}
	else
		philo->n_must = -1;
	return (NORMAL);
}

void	dinning(t_philo *philo)
{
	if (pthread_create(&(philo->th_rout), NULL, routine, philo)
		|| pthread_create(&(philo->th_die), NULL, die_check, philo))
		thread_error(philo);
	if (pthread_join(philo->th_rout, NULL) || pthread_join(philo->th_die, NULL))
		thread_error(philo);
	//error만 실행하면 이 철학자만 죽고 나머지 철학자들은 계속 동작하므로
	//pthread_error함수를 만들어서 error + die세마포어도 켜주는 식으로
	//만들어서 모든 프로세스를 종료시켜줌.
}

void	finish_dinning(t_philo *philo, pid_t *pid_array)
{
	free(pid_array);
	sem_close(philo->sem.die);
	sem_close(philo->sem.full);
	sem_close(philo->sem.fork);
	sem_close(philo->sem.print);
	sem_unlink("die");
	sem_unlink("full");
	sem_unlink("fork");
	sem_unlink("print");
	exit(0);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	pid_t	*pid_array;
	pid_t	ret;

	if (!(ac == 5 || ac == 6) || save_arg(ac, av, &philo))
		input_error();
	setup_dinner(&philo, &pid_array);
	ret = make_philo(&philo, pid_array);
	if (ret == 0)
		dinning(&philo);//자식들의 동작
	else
	{
		check_main(&philo, pid_array);//부모 프로세스의 동작
		finish_dinning(&philo, pid_array);
	}
	return (0);
}
