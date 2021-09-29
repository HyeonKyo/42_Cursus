/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:20:18 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/25 17:20:20 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

#include <stdio.h>//지우기
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

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

pid_t	g_server_pid;

/*
** =============================================================================
** Union Type Definitions
** =============================================================================
*/

typedef union u_info
{
	int		num;
	char	arr[4];
}			t_info;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct sigaction	t_act;

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

int		ft_isdigit(int c);
void	ft_putnbr(unsigned int n);
void	ft_putchar(char c);
void	ft_putstr(char *str, int fd);
void	ft_putendl(char *str, int fd);
void	*ft_memset(void *ptr, int value, size_t num);
size_t	ft_strlen(const char *str);
int		mt_atoi(const char *str);
void	setup_act(t_act *act, void (*handler)(int, siginfo_t *, void *));

void	error(char *str);
void	input_error(void);
void	sigerror(void);

/*
** =============================================================================
** Server Functions
** =============================================================================
*/
void	bit_masking(char *c, int signo);
int		get_client_pid(pid_t *client_pid, siginfo_t *info);

void	send_len(int str_len);
void	send_message(char *str, int len);
void	send_string(char *str, int len, t_act *act);

/*
** =============================================================================
** Client Functions
** =============================================================================
*/

int		return_mask_number(int mask_num);

#endif
