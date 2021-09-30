/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:36:04 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 16:36:06 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	setup_dinner(t_philo *philo, pid_t **pid_array)
{
	philo->cnt_eat = 0;
	/*
	**	세마포어 open / 권한 어떻게?
	**	함수 리턴 값 체크 추가하기
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
