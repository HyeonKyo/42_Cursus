#include "bonus.h"

static int	check_cmd(char *line, int len)
{
	if (len < 2 || len > 3)
		return (FALSE);
	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0
		|| ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "pa") == 0
		|| ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "ra") == 0
		|| ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0
		|| ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0
		|| ft_strcmp(line, "rrr") == 0)
		return (TRUE);
	return (FALSE);
}

static void	make_cmd_list(t_cmd_deq *cmd)
{
	char		*line;
	int			len;
	int			flag;

	flag = TRUE;
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		len = (int)ft_strlen(line);
		if (check_cmd(line, len) == FALSE)
			flag = FALSE;
		add_command(len, line, cmd);
		free(line);
		line = 0;
	}
	if (flag == FALSE)
		error();
	return ;
}

static int	check_sorted(t_deque *deq, int len)
{
	if (deq->size_a != len || deq->size_b != 0)
		return (0);
	if (!check_already_sorted(deq, deq->size, DESCEND))
		return (0);
	return (1);
}

static void	print_result(int ret)
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

	if (ac <= 1)
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
