
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
#include <semaphore.h>
#include <sys/time.h>

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define FALSE 0
# define TRUE 1

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

typedef enum	e_cond
{
	LIFE,
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

typedef struct	s_node
{
	int				n;
	t_mutex			fk_mtx;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_info
{
	int			n_philo;
	int			tm_die;
	int			tm_eat;
	int			tm_sleep;
	int			n_must;
	int			full_cnt;
	long long	begin;
	t_node		**fork;
	t_cond		cond;
	t_mutex		full_mtx;
	t_mutex		pt_mtx;
}				t_info;

typedef struct	s_philo
{
	int			i;
	int			num;
	int			left;
	int			right;
	int			n_eat;
	long long	tm_life;
	t_pth		th;
	t_pth		ck;
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

void	make_fork(t_info *inf);

void	save_time(long long *time);

int		print_state(t_cond cond);
int		state_message(t_philo *philo, t_cond cond);

/*
** =============================================================================
** Subject Sources
** =============================================================================
*/

void	putdown_fork(t_philo *philo);
void	*routine(void *data);
void	*lifetime(void *data);
int		check_condition(t_info *inf);

#endif
