/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:02:34 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/30 21:43:37 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/time.h>

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define FALSE 0
# define TRUE 1

# define ERROR 1
# define NORMAL 0

# define INT_MAX 2147483647

# define MILLI 1000
# define DELTA 10
# define ITER 200

# define AVAILABLE 2
# define ISEVEN 1

/*
** =============================================================================
** Type Definition
** =============================================================================
*/

typedef pthread_t		t_pth;
typedef pthread_mutex_t	t_mutex;

/*
** =============================================================================
** Enum type Definition
** =============================================================================
*/

typedef enum e_cond
{
	LIFE,
	DEAD,
	GRAB,
	EATING,
	SLEEPING,
	THINKING,
	FULL
}			t_cond;

/*
** =============================================================================
** Struct type Definition
** =============================================================================
*/

typedef struct s_node
{
	int				n;
	t_mutex			fk_mtx;
	struct s_node	*next;
	struct s_node	*prev;
}			t_node;

typedef struct s_sem
{
	sem_t		*fork;
	sem_t		*die;
	sem_t		*full;
	sem_t		*print;
}			t_sem;

typedef struct s_philo
{
	int			i;
	int			num;
	int			n_philo;
	int			tm_die;
	int			tm_eat;
	int			tm_sleep;
	int			n_must;
	int			cnt_eat;
	long long	begin;
	long long	tm_life;
	t_pth		th_rout;
	t_pth		th_die;
	t_pth		th_full;
	t_sem		sem;
}			t_philo;

/*
** =============================================================================
** Hk_function Sources
** =============================================================================
*/

int		ft_atoi(const char *str, int *val);
void	ft_putnbr(int n, int fd);
void	ft_putstr(char *s, int fd);
void	ft_putendl(char *s, int fd);
int		ft_strlen(char *str);

/*
** =============================================================================
** Utility Sources
** =============================================================================
*/

void	error(char *str);
void	merror(void *ret);
void	input_error(void);
void	thread_error(t_philo *philo);

void	save_time(long long *time);

int		print_state(t_cond cond);
void	state_message(t_philo *philo, t_cond cond);

/*
** =============================================================================
** Subject Sources
** =============================================================================
*/

int		make_philo(t_philo *philo, pid_t *pid_array);
void	setup_dinner(t_philo *philo, pid_t **pid_array);

void	*routine(void *data);
void	*die_check(void *data);
void	*full_check(void *data);
void	check_main(t_philo *philo, pid_t *pid_array);

#endif
