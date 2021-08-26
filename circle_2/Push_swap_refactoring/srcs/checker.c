#include "bonus.h"

t_cmd_deq	*make_cmd_list(void)
{
	t_cmd_deq	*cmd;
	char		*line;
	int			len;

	cmd = create_cmd_deque();
	while (get_next_line(0, &line) > 0)
	{
		len = (int)ft_strlen(line);
		add_command(len, line, cmd);
		free(line);
		line = 0;
	}
	return (cmd);
}

void	execute_cmd(t_cmd_deq *cmd, t_deque *deq_A, t_deque *deq_B)
{
	t_cmd_lst	*cur;
	char		*str;

	cur = cmd->head;
	while (cur)
	{
		str = cur->cmd;
		if (!ft_strcmp(str, "sa"))
			sa_bns(deq_A);
		else if (!ft_strcmp(str, "sb"))
			sb_bns(deq_B);
		else if (!ft_strcmp(str, "ss"))
			ss_bns(deq_A, deq_B);
		else if (!ft_strcmp(str, "pa"))
			pa_bns(deq_A, deq_B);
		else if (!ft_strcmp(str, "pb"))
			pb_bns(deq_A, deq_B);
		else if (!ft_strcmp(str, "ra"))
			ra_bns(deq_A);
		else if (!ft_strcmp(str, "rb"))
			rb_bns(deq_B);
		else if (!ft_strcmp(str, "rr"))
			rr_bns(deq_A, deq_B);
		else if (!ft_strcmp(str, "rra"))
			rra_bns(deq_A);
		else if (!ft_strcmp(str, "rrb"))
			rrb_bns(deq_B);
		else if (!ft_strcmp(str, "rrr"))
			rrr_bns(deq_A, deq_B);
		cur = cur->next;
	}
}

int	check_sorted(t_deque *deq_A, t_deque *deq_B, int len)
{
	if (deq_A->size != len || deq_B->size != 0)
		return (0);
	if (!check_already_sorted(deq_A))
		return (0);
	return (1);
}

void	print_result(int ret)
{
	if (ret == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_deque		*deq;
	t_cmd_deq	*cmd;
	int			ret;
	int			len;

	if (ac <= 1)//ac = 2 -> 인자 1개 => "1 2 34" 이런식으로 여러개 들어올 수 있음.
		return (1);
	deq = make_stack(ac, av);
	len = deq->size;
	cmd = make_cmd_list();
	execute_cmd(cmd, deq);
	ret = check_sorted(deq, deq_B, len);
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
