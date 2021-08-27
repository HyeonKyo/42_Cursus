#include "bonus.h"

static void	execute_case1(t_deque *deq, char *str)
{
	if (!ft_strcmp(str, "sa"))
		sa_bns(deq);
	else if (!ft_strcmp(str, "sb"))
		sb_bns(deq);
	else if (!ft_strcmp(str, "ss"))
		ss_bns(deq);
	else if (!ft_strcmp(str, "pa"))
		pa_bns(deq);
	else if (!ft_strcmp(str, "pb"))
		pb_bns(deq);
}

static void	execute_case2(t_deque *deq, char *str)
{
	if (!ft_strcmp(str, "ra"))
		ra_bns(deq);
	else if (!ft_strcmp(str, "rb"))
		rb_bns(deq);
	else if (!ft_strcmp(str, "rr"))
		rr_bns(deq);
	else if (!ft_strcmp(str, "rra"))
		rra_bns(deq);
	else if (!ft_strcmp(str, "rrb"))
		rrb_bns(deq);
	else if (!ft_strcmp(str, "rrr"))
		rrr_bns(deq);
}

void	execute_cmd(t_deque *deq)
{
	t_cmd_deq	*cmd;
	t_cmd_lst	*cur;
	char		*str;

	cmd = deq->cmd;
	cur = cmd->head;
	while (cur)
	{
		str = cur->cmd;
		if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "sb")
		|| !ft_strcmp(str, "ss") || !ft_strcmp(str, "pa")
		|| !ft_strcmp(str, "pb"))
			execute_case1(deq, str);
		else
			execute_case2(deq, str);
		cur = cur->next;
	}
}
