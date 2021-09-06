/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:58 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/07 00:32:16 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define TRUE 1
# define FALSE 0
# define RIGHT 0
# define MID 1
# define LEFT 2
# define ASCEND 1
# define DESCEND 0

/*
** =============================================================================
** Type Definitions
** =============================================================================
*/

typedef long long	t_ll;

/*
** =============================================================================
** Struct Type Definitions
** =============================================================================
*/

typedef struct s_cmd_lst
{
	char				*cmd;
	struct s_cmd_lst	*next;
	struct s_cmd_lst	*prev;
}			t_cmd_lst;

typedef struct s_cmd_deq
{
	int			size;
	t_cmd_lst	*head;
	t_cmd_lst	*last;
}			t_cmd_deq;

typedef struct s_list
{
	int				data;
	int				end_flag;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

typedef struct s_deque
{
	int				size;
	int				size_a;
	int				size_b;
	t_list			*cursor;
	t_list			*end_A;
	t_list			*end_B;
	t_list			*end_node;
	t_cmd_deq		*cmd;
}			t_deque;

/*
** =============================================================================
** Hk_func Functions
** =============================================================================
*/

unsigned int	ft_absol(int n);
int				ft_isdigit(int c);
void			*ft_memset(void *ptr, int value, size_t num);
void			ft_putendl(char *str, int fd);
void			ft_putstr(char *str, int fd);
char			*ft_strchr(char *str, int c);
int				ft_strcmp(char *s1, const char *s2);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
int				get_next_line(int fd, char **line);

/*
** =============================================================================
** Utility Functions
** =============================================================================
*/

void			swap_number(int *a, int *b);
int				find_max(int n1, int n2, int n3);
int				find_min(int n1, int n2, int n3);

void			error(void);
void			merror(void *ptr);

void			check_valid_argv(int ac, char **argv);
char			*merge_input(int ac, char **av);
t_deque			*make_stack(int ac, char **av);

void			sa(t_deque *deq);
void			sb(t_deque *deq);
void			ss(t_deque *deq);
void			pa(t_deque *deq);
void			pb(t_deque *deq);
int				ra(t_deque *deq);
int				rb(t_deque *deq);
void			rr(t_deque *deq);
int				rra(t_deque *deq);
int				rrb(t_deque *deq);
void			rrr(t_deque *deq);

t_list			*create_node(void);
t_deque			*create_deque(void);
void			clear_deque(t_deque *deq);
void			remove_node(t_list *cur);

void			fillin_deque(t_deque *deq, int num);
void			link_node(t_list *n1, t_list *n2);

char			*new_str(int len, const char *str);
t_cmd_lst		*create_cmd_list(void);
t_cmd_deq		*create_cmd_deque(void);
void			del_cmd_last_node(t_cmd_deq *cmd);
void			clear_cmd_deq(t_cmd_deq *cmd);

void			add_command(int len, const char *str, t_cmd_deq *cmd);
void			print_cmd(t_cmd_deq *cmd);
void			replace_cmd(t_cmd_deq *cmd, t_cmd_lst **cur, const char *str);
void			delete_command(t_cmd_deq *cmd, t_cmd_lst **cur);

/*
** =============================================================================
** Subject Functions
** =============================================================================
*/

int				check_already_sorted(t_deque *deq, int size, int order);

void			merge_to_a(t_deque *deq, int *len, int order);
void			merge_to_b(t_deque *deq, int *len, int order);
void			sort_skip(t_deque *deq, int size, int order);
void			sort_fix(t_deque *deq, int size, int order);
void			sort(t_deque *deq);

void			except_sort_fix(t_deque *deq, int size, int order);
void			except_sort_skip(t_deque *deq, int size, int order);

int				optimize_command(t_cmd_deq *cmd);
#endif
