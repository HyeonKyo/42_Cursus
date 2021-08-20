/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:51 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:52 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"
#include "ft_utils.h"
#include <stdio.h>

char	*new_str(int len, const char *str)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(len + 1));
	if (new == 0)
		merror();
	i = -1;
	while (++i < len)
		new[i] = str[i];
	new[len] = 0;
	return (new);
}

t_cmd_lst	*create_cmd_list(void)
{
	t_cmd_lst	*lst;

	lst = (t_cmd_lst *)malloc(sizeof(t_cmd_lst));
	if (lst == 0)
		merror();
	ft_memset(lst, 0, sizeof(t_cmd_lst));
	return (lst);
}

void	add_command(int len, const char *str, t_cmd_deq *cmd_list)
{
	cmd_list->last->cmd = new_str(len, str);
	cmd_list->last->next = create_cmd_list();
	cmd_list->last->next->prev = cmd_list->last;
	cmd_list->last = cmd_list->last->next;
	cmd_list->size++;
}

t_cmd_deq	*create_cmd_deque(void)
{
	t_cmd_deq	*cmd;

	cmd = (t_cmd_deq *)malloc(sizeof(t_cmd_deq));
	if (cmd == 0)
		merror();
	cmd->head = create_cmd_list();
	cmd->last = cmd->head;
	cmd->size = 0;
	return (cmd);
}

void	setup_info(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	ft_memset(*info, 0, sizeof(t_info));
	(*info)->cmd = create_cmd_deque();
	ft_memset((*info)->cnt, 0, sizeof(int) * 4);
}

void	clear_info(t_info *info)
{
	t_cmd_lst	*cur;
	t_cmd_lst	*tmp;

	cur = info->cmd->head;
	while (cur == 0)
	{
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(info);
}