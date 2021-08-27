#include "push_swap.h"

void	print_cmd(t_cmd_deq *cmd)
{
	t_cmd_lst	*cur;

	cur = cmd->head;
	while (cur->cmd != NULL)
	{
		ft_putendl(cur->cmd, STDOUT_FILENO);
		cur = cur->next;
	}
}

void	replace_command(t_cmd_deq *cmd, t_cmd_lst **cur, const char *str)
{
	t_cmd_lst	*lst;
	t_cmd_lst	*tmp;
	int			len;

	lst = create_cmd_list();
	len = (int)ft_strlen(str);
	lst->cmd = new_str(len, str);
	lst->prev = (*cur)->prev;
	(*cur)->prev->next = lst;
	lst->next = (*cur)->next->next;
	(*cur)->next->next->prev = lst;
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	cmd->size--;
}

void	delete_command(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	t_cmd_lst	*tmp;

	if ((*cur)->prev)
		(*cur)->prev->next = (*cur)->next->next;
	else
		cmd->head = (*cur)->next->next;
	if ((*cur)->next->next)
		(*cur)->next->next->prev = (*cur)->prev;
	else
		cmd->last = (*cur)->prev;
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	tmp = *cur;
	*cur = (*cur)->next;
	free(tmp);
	cmd->size -= 2;
}
