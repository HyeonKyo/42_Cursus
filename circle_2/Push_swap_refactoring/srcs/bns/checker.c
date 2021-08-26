#include "bonus.h"

void	make_cmd_list(t_cmd_deq *cmd)
{
	char		*line;
	int			len;

	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		len = (int)ft_strlen(line);
		add_command(len, line, cmd);
		free(line);
		line = 0;
	}
	return ;
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
		else if (!ft_strcmp(str, "ra"))
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
		cur = cur->next;
	}
}

int	check_sorted(t_deque *deq, int len)
{
	if (deq->size_a != len || deq->size_b != 0)
		return (0);
	if (!check_already_sorted(deq, deq->size, DESCEND))
		return (0);
	return (1);
}

void	print_result(int ret)
{
	if (ret == 1)
		ft_putendl("OK", STDOUT_FILENO);
	else
		ft_putendl("KO", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_deque		*deq;
	int			ret;
	int			len;

	if (ac <= 1)//ac = 2 -> 인자 1개 => "1 2 34" 이런식으로 여러개 들어올 수 있음.
		return (1);
	deq = make_stack(ac, av);
	len = deq->size;
	make_cmd_list(deq->cmd);
	execute_cmd(deq);
	ret = check_sorted(deq, len);
	print_result(ret);
	clear_deque(deq);
	/*
	입력으로 들어오는 명령들 리스트 저장(read함수 사용)
	리스트 문자 하나씩 strcmp로 비교 후 맞는 명령어 실행
	다 실행 후 스택 A가 정렬, 길이 맞는지, 스택B는 비어있는지
	-> 다 됐으면 ok 아니면 ko출력
	clear스택, 리턴 0
	*/
	return (0);
}
