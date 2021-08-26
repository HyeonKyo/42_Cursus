/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:51 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/26 20:31:38 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*new_str(int len, const char *str)
{
	int		i;
	char	*new;

	new = (char *)malloc(sizeof(len + 1));
	merror(new);
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
	merror(lst);
	ft_memset(lst, 0, sizeof(t_cmd_lst));
	return (lst);
}

void	add_command(int len, const char *str, t_cmd_deq *cmd)
{
	cmd->last->cmd = new_str(len, str);
	cmd->last->next = create_cmd_list();
	cmd->last->next->prev = cmd->last;
	cmd->last = cmd->last->next;
	cmd->size++;
}

t_cmd_deq	*create_cmd_deque(void)
{
	t_cmd_deq	*cmd;

	cmd = (t_cmd_deq *)malloc(sizeof(t_cmd_deq));
	merror(cmd);
	cmd->head = create_cmd_list();
	cmd->last = cmd->head;
	cmd->size = 0;
	return (cmd);
}

void	del_cmd_last_node(t_cmd_deq *cmd)
{
	t_cmd_lst	*del;
	t_cmd_lst	*pre;

	if (cmd == NULL || cmd->size == 0)
		return ;
	del = cmd->last->prev;
	pre = del->prev;
	if (pre != NULL)
		pre->next = cmd->last;
	cmd->last->prev = pre;
	free(del->cmd);
	free(del);
	cmd->size--;
}

void	clear_cmd_deq(t_cmd_deq *cmd)
{
	int	size;

	size = cmd->size;
	while (size--)
	{
		del_cmd_last_node(cmd);
	}
	if (cmd->last->cmd)
		free(cmd->last->cmd);
	free(cmd->last);
	free(cmd);
}
