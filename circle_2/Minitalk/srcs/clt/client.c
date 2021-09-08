#include "minitalk.h"

void	catch_signal(int sig, siginfo_t *info, void *context)
{
	if (context == NULL)
		return ;
	if (info->si_pid != g_server_pid)
		sigerror();
	if (sig == SIGUSR1)//문자열 보내는 중에 서버가 USR1시그널을 보내면 오류.
		sigerror();
}

int	return_mask_number(int mask_num)
{
	if (mask_num == 8)
		return (MASK8);
	else if (mask_num == 7)
		return (MASK7);
	else if (mask_num == 6)
		return (MASK6);
	else if (mask_num == 5)
		return (MASK5);
	else if (mask_num == 4)
		return (MASK4);
	else if (mask_num == 3)
		return (MASK3);
	else if (mask_num == 2)
		return (MASK2);
	else if (mask_num == 1)
		return (MASK1);
	else
		return (0);
}

static int	check_pid(char *av1)
{
	int	i;

	i = -1;
	if (av1[0] == '+')
		i++;
	while (av1[++i])
	{
		if (!ft_isdigit(av1[i]))
			error("Input error");
	}
	return (mt_atoi(av1));
}

void	setup_input(char **av, t_act *act, char **str, int *len)
{
	g_server_pid = check_pid(av[1]);
	setup_act(act, catch_signal);
	*str = av[2];
	*len = (int)ft_strlen(*str);
}

int	main(int ac, char **av)
{
	char	*str;
	int		str_len;
	t_act	act;

	if (ac < 2)
		input_error();
	setup_input(av, &act, &str, &str_len);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	send_len(str_len);
	send_string(str, str_len, &act);
	while (1)
		pause();
	return (0);
}
