#include "philo.h"

int	save_arg(int ac, char **av, t_info *inf)
{
	if (!(ft_atoi(av[1], &inf->n_philo) && ft_atoi(av[2], &inf->tm_die)
		&& ft_atoi(av[3], &inf->tm_eat) && ft_atoi(av[4], &inf->tm_sleep)))
		return (FALSE);
	if (ac == 6)
	{
		if (!ft_atoi(av[5], &inf->n_must))
			return (FALSE);
	}
	else
		inf->n_must = -1;
	return (TRUE);
}

int	philo_initialization(t_philo **philo, t_info *inf)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * inf->n_philo);
	if (merror(*philo) == ERROR)
		return (ERROR);
	i = 0;
	while (i < inf->n_philo)
	{
		(*philo)[i].i = i;
		(*philo)[i].left = i - 1;
		if ((*philo)[i].left < 0)
			(*philo)[i].left = inf->n_philo - 1;
		(*philo)[i].right = i + 1;
		if ((*philo)[i].right == inf->n_philo)
			(*philo)[i].right = 0;
		(*philo)[i].num = i + 1;
		(*philo)[i].n_eat = 0;
		(*philo)[i++].inf = inf;
	}
	return (NORMAL);
}

static int	setup_dinner(t_philo **philo, t_info *inf)
{
	inf->cond = LIFE;
	inf->full_cnt = 0;
	if (pthread_mutex_init(&(inf->full_mtx), NULL)
		|| pthread_mutex_init(&(inf->pt_mtx), NULL))
		{
			ft_putendl("Mutex error", STDERR_FILENO);
			return (ERROR);
		}
	if (make_fork(inf) == ERROR || philo_initialization(philo, inf) == ERROR)
	{
		free_fork(inf);
		return (ERROR);
	}
	return (NORMAL);
}

void	dinning(t_philo *philo)
{
	int		i;
	t_info	*inf;

	inf = philo->inf;
	save_time(&inf->begin);
	i = -1;
	while (++i < inf->n_philo)
	{
		philo[i].tm_life = inf->begin;
		pthread_create(&(philo[i].th), NULL, routine, &(philo[i]));
		pthread_create(&(philo[i].ck), NULL, lifetime, &(philo[i]));
	}
	i = -1;
	while (++i < inf->n_philo)
	{
		pthread_join(philo[i].th, NULL);
		pthread_join(philo[i].ck, NULL);
	}
}

static void	finish_dinning(t_philo *philo, t_info *inf)
{
	if (pthread_mutex_destroy(&(inf->full_mtx))
		|| pthread_mutex_destroy(&(inf->pt_mtx)))
			ft_putendl("Mutex error", STDERR_FILENO);
	free_fork(inf);
	free(philo);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	inf;

	if (!(ac == 5 || ac == 6) || !save_arg(ac, av, &inf))
		return (usage());
	if (setup_dinner(&philo, &inf) == ERROR)
		return (ERROR);
	dinning(philo);
	finish_dinning(philo, &inf);
	return (0);
}
