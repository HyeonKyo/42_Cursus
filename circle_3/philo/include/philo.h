
#ifndef PHILO_H
# define PHILO_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define FALSE 0
# define TRUE 1
# define MILLI 1000
# define DELTA 5
# define AVAILABLE 2
# define ISEVEN 1
# define HUNGRY 2
# define GOOD 1

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

typedef enum	e_cond
{
	DEAD,
	GRAB,
	EATING,
	SLEEPING,
	THINKING,
	FULL
}				t_cond;

/*
** =============================================================================
** Struct type Definition
** =============================================================================
*/

typedef struct	s_info
{
	int			n_philo;
	int			tm_die;
	int			tm_eat;
	int			tm_sleep;
	int			n_must;
	int			*fork;
	int			full_cnt;
	long long	begin;
	t_pth		ck_odd;
	t_pth		ck_even;
	t_mutex		full_mtx;
	t_mutex		fk_mtx;
	t_mutex		pt_mtx;
}				t_info;

typedef struct	s_philo
{
	int			i;
	int			num;
	int			left;
	int			right;
	int			n_eat;
	int			priority;
	long long	tm_life;
	t_pth		th;
	t_pth		ck;
	t_cond		cond;
	t_info		*inf;
}				t_philo;

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

void	save_time(long long *time);

void	print_state(t_philo *philo);
void	state_message(t_philo *philo);
void	all_is_full(void);

/*
** =============================================================================
** Subject Sources
** =============================================================================
*/

void	putdown_fork(t_philo *philo);
void	*routine(void *data);
void	*lifetime(void *data);

#endif
