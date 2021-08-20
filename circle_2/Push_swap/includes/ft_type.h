/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:28 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:28 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPE_H
# define FT_TYPE_H
# include <stdlib.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef long long	t_ll;

//stack
typedef struct	s_list
{
	int	data;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct	s_deque
{
	int		size;
	int		case_num;
	t_list	*top;
	t_list	*bot;
}				t_deque;

//command
typedef struct	s_cmd_lst
{
	char	*cmd;
	struct s_cmd_lst	*next;
	struct s_cmd_lst	*prev;
}				t_cmd_lst;

typedef struct	s_cmd_deq
{
	int		size;
	t_cmd_lst	*head;
	t_cmd_lst	*last;
}				t_cmd_deq;

//pre sort
typedef struct	s_qu_lst
{
	t_ll	data;
	struct s_qu_lst	*next;
}				t_qu_lst;

typedef struct	s_queue
{
	int	size;
	t_qu_lst	*fst;
	t_qu_lst	*last;
}				t_queue;

typedef struct	s_sort
{
	int		size;
	t_ll	*arr;
}				t_sort;

//pivot
typedef	struct	s_pivot
{
	int	big;
	int	sml;
}				t_pivot;

//information?
typedef	struct	s_info
{
	t_pivot		piv;
	t_cmd_deq	*cmd;
	int			cnt[4];
}				t_info;
#endif
