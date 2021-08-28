#include "push_swap.h"

static void	optimizing_check1(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	char	*str;

	str = (*cur)->next->cmd;
	if (!ft_strcmp((*cur)->cmd, "ra"))
	{
		if (!ft_strcmp(str, "rrr"))
			replace_cmd(cmd, cur, "rrb");
		else if (!ft_strcmp(str, "rb"))
			replace_cmd(cmd, cur, "rr");
		else if (!ft_strcmp(str, "rra"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp((*cur)->cmd, "rb"))
	{
		if (!ft_strcmp(str, "rrr"))
			replace_cmd(cmd, cur, "rra");
		else if (!ft_strcmp(str, "ra"))
			replace_cmd(cmd, cur, "rr");
		else if (!ft_strcmp(str, "rrb"))
			delete_command(cmd, cur);
	}
}

static void	optimizing_check2(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	char	*cur_str;
	char	*next_str;

	cur_str = (*cur)->cmd;
	next_str = (*cur)->next->cmd;
	if (!ft_strcmp(cur_str, "rra"))
	{
		if (!ft_strcmp(next_str, "rrb"))
			replace_cmd(cmd, cur, "rrr");
		else if (!ft_strcmp(next_str, "ra"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp(cur_str, "rrb"))
	{
		if (!ft_strcmp(next_str, "rra"))
			replace_cmd(cmd, cur, "rrr");
		else if (!ft_strcmp(next_str, "rb"))
			delete_command(cmd, cur);
	}
}

static void	optimizing_check3(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	char	*str;

	str = (*cur)->next->cmd;
	if (!ft_strcmp((*cur)->cmd, "rr"))
	{
		if (!ft_strcmp(str, "rra"))
			replace_cmd(cmd, cur, "rb");
		else if (!ft_strcmp(str, "rrb"))
			replace_cmd(cmd, cur, "ra");
		else if (!ft_strcmp(str, "rrr"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp((*cur)->cmd, "rrr"))
	{
		if (!ft_strcmp(str, "ra"))
			replace_cmd(cmd, cur, "rrb");
		else if (!ft_strcmp(str, "rb"))
			replace_cmd(cmd, cur, "rra");
		else if (!ft_strcmp(str, "rr"))
			delete_command(cmd, cur);
	}
}

static void	optimizing_check4(t_cmd_deq *cmd, t_cmd_lst **cur)
{
	char	*str;

	str = (*cur)->next->cmd;
	if (!ft_strcmp((*cur)->cmd, "pa"))
	{
		if (!ft_strcmp(str, "pb"))
			delete_command(cmd, cur);
	}
	else if (!ft_strcmp((*cur)->cmd, "pb"))
	{
		if (!ft_strcmp(str, "pa"))
			delete_command(cmd, cur);
	}
}

int	optimize_command(t_cmd_deq *cmd)
{
	t_cmd_lst	*cur;
	t_cmd_lst	*tmp;
	int			fg;

	if (cmd == NULL)
		return (0);
	cur = cmd->head;
	fg = 0;
	while (cur && cur->next)
	{
		tmp = cur;
		if (!ft_strcmp(cur->cmd, "ra") || !ft_strcmp(cur->cmd, "rb"))
			optimizing_check1(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "rra") || !ft_strcmp(cur->cmd, "rrb"))
			optimizing_check2(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "rrr") || !ft_strcmp(cur->cmd, "rr"))
			optimizing_check3(cmd, &cur);
		else if (!ft_strcmp(cur->cmd, "pa") || !ft_strcmp(cur->cmd, "pb"))
			optimizing_check4(cmd, &cur);
		if (tmp == cur)
			cur = cur->next;
		else
			fg = 1;
	}
	return (fg);
}

/*
	1. if ra
		if next = rrr => rrb => 2개를 1개로 -> replace cmd()
		if next = rra => x -> 2개를 삭제 -> delete cmd()
		if next = rb => rr -> replace cmd()
	2. if rb
		if next = rrr => rra
		if next = rrb => x
		if next = ra => rr
	3. if rra
		if next = ra => x
		if next = rrb => rrr
	4. if rrb
		if next = rb => x
		if next = rra => rrr
	5. rrr
		ra => rrb
		rb => rra
	*/
