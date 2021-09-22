#include "philo_bonus.h"

int	save_arg(int ac, char **av, t_philo *philo)
{
	if (!(ft_atoi(av[1], &(philo->n_philo)) && ft_atoi(av[2], &(philo->tm_die))
		&& ft_atoi(av[3], &(philo->tm_eat)) && ft_atoi(av[4], &(philo->tm_sleep))))
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

void	setup_dinner(t_philo *philo, pid_t **pid_array)
{
	philo->cnt_eat = 0;
	/*
	세마포어 open / 권한 어떻게?
	함수 리턴 값 체크 추가하기
	*/
	philo->sem.die = sem_open("die", O_CREAT | O_EXCL, 744, 0);
	philo->sem.full = sem_open("full", O_CREAT | O_EXCL, 744, 0);
	philo->sem.fork = sem_open("fork", O_CREAT | O_EXCL, 744, philo->n_philo);
	philo->sem.print = sem_open("print", O_CREAT | O_EXCL, 744, 1);
	*pid_array = (pid_t *)malloc(sizeof(pid_t) * philo->n_philo);
	merror(*pid_array);
	save_time(&(philo->begin));
	philo->tm_life = philo->begin;
}

void	dinning(t_philo *philo)
{
	if (pthread_create(&(philo->th_rout), NULL, routine, philo)
		|| pthread_create(&(philo->th_die), NULL, die_check, philo))
	{
		sem_post(philo->sem.die);
		error("thread error!");
	}
	if (pthread_join(philo->th_rout, NULL) || pthread_join(philo->th_die, NULL))
	{
		sem_post(philo->sem.die);
		error("thread error!");
	}
	//error만 실행하면 이 철학자만 죽고 나머지 철학자들은 계속 동작하므로
	//pthread_error함수를 만들어서 error + die세마포어도 켜주는 식으로
	//만들어서 모든 프로세스를 종료시켜줌.
}

void	check_main(t_philo *philo, pid_t *pid_array)
{
	int	i;

	usleep(100);
	i = -1;
	if (philo->n_must > 0)
	{
		if (pthread_create(&philo->th_full, NULL, full_check, philo)
			|| pthread_detach(philo->th_full))
			{
				sem_wait(philo->sem.print);
				ft_putendl("Thread error!", STDERR_FILENO);
				sem_post(philo->sem.die);
			}
	}
	sem_wait(philo->sem.die);
	while (++i < philo->n_philo)
		kill(pid_array[i], SIGTERM);
	i = -1;
	while (++i < philo->n_philo)
		waitpid(0, NULL, 0);
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

int	make_philo(t_philo *philo, pid_t *pid_array)
{
	pid_t	ret;
	int		i;

	i = -1;
	while (++i < philo->n_philo)
	{
		ret = fork();
		if (ret == 0)//자식
		{
			philo->i = i;
			philo->num = i + 1;
			break ;
		}
		pid_array[i] = ret;
	}
	return (ret);
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
