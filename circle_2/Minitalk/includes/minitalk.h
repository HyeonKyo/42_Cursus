#ifndef MINITALK_H
# define MINITALK_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define ADD_BIT 1
# define MASK8 128
# define MASK7 64
# define MASK6 32
# define MASK5 16
# define MASK4 8
# define MASK3 4
# define MASK2 2
# define MASK1 1

/*
** =============================================================================
** Union Type Definitions
** =============================================================================
*/

typedef union u_info
{
	unsigned int	num;
	char	arr[4];
}			t_info;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct sigaction t_act;

pid_t	g_server_pid;

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

int	ft_isdigit(int c);
void	ft_putnbr(unsigned int n);
void	print_char(char c);
void	*ft_memset(void *ptr, int value, size_t num);
size_t	ft_strlen(const char *str);
int	mt_atoi(const char *str);
void	sigerror(void);
void	error(char *str);
void	setup_act(t_act *act, void (*handler)(int, siginfo_t *, void *));

/*
** =============================================================================
** Server Functions
** =============================================================================
*/
void	bit_masking(char *c, int signo);
void	get_client_pid(pid_t *client_pid, siginfo_t *info);

void	send_len(unsigned int str_len);
void	send_message(char *str, int len);

/*
** =============================================================================
** Client Functions
** =============================================================================
*/



#endif
