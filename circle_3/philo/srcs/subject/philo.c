#include "philo.h"

int	save_arg(int ac, char **av, t_info *inf)
{
	if (!(ft_atoi(av[1], &inf->n_philo) && ft_atoi(av[2], &inf->tm_die)
	&& ft_atoi(av[3], &inf->tm_eat) && ft_atoi(av[4], &inf->tm_sleep)))
		return (FALSE);
	if (ac == 6)
		if (!ft_atoi(av[5], &inf->n_must))
			return (FALSE);
	return (TRUE);
	//다른 저장 작업도 실행
}

void	setup_dinner(t_philo **philo, t_info *inf)
{
	int	i;

	i = 0;
	//1. make fork, philo
	*philo = (t_philo *)malloc(sizeof(t_philo) * inf->n_philo);
	merror(*philo);
	inf->fork = (int *)malloc(sizeof(int) * inf->n_philo);
	merror(inf->fork);
	inf->full_cnt = 0;
	//2. init mutex
	pthread_mutex_init(&(inf->fk_mtx), NULL);
	pthread_mutex_init(&(inf->tm_mtx), NULL);
	pthread_mutex_init(&(inf->pt_mtx), NULL);
	//3. initalize philo
	save_time(&inf->begin);
	while (i < inf->n_philo)
	{
		inf->fork[i] = 2;
		(*philo)[i].i = i;
		(*philo)[i].left = i - 1;
		if ((*philo)[i].left < 0)
			(*philo)[i].left = inf->n_philo - 1;
		(*philo)[i].right = i + 1;
		if ((*philo)[i].right == inf->n_philo)
			(*philo)[i].right = 0;
		(*philo)[i].num = i + 1;
		(*philo)[i].n_eat = 0;
		(*philo)[i].cond = GRAB;
		(*philo)[i].tm_life = inf->begin;
		(*philo)[i++].inf = inf;
	}
}

void	dinning(t_philo *philo)
{
	int	i;
	t_info	*inf;

	inf = philo->inf;
	i = 0;
	while (i < inf->n_philo)
	{
		philo[i].tm_life = inf->begin;
		pthread_create(&philo[i].th, NULL, routine, &(philo[i]));
		if (i == 0)
			pthread_create(&philo[i].ck, NULL, lifetime, philo);
		i++;
	}
	i = 0;
	while (i < inf->n_philo)
	{
		pthread_join(philo[i].th, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	inf;

	if (!(ac == 5 || ac == 6) || !save_arg(ac, av, &inf))
		input_error();
	setup_dinner(&philo, &inf);
	dinning(philo);
	return (0);
}
