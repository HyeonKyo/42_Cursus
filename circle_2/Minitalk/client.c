#include "minitalk.h"
#include "utils.h"
int	g_flag = 0;

int	check_pid(char *argv1)
{
	int	i;

	i = -1;
	if (argv1[0] == '+')
		i++;
	while (argv1[++i])
	{
		if (!ft_isdigit(argv1[i]))
			error("Input error");
	}
	return (mt_atoi(argv1));
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

void	catch_signal(int sig, siginfo_t *info, void *context)
{
	if (info->si_pid != g_server_pid)
		sigerror();
	if (g_flag == 0)//g_flag는 문자열을 다 전달하면 1이 된다.
	{
		if (sig == SIGUSR1)
			sigerror();
	}
	else
	{
		if (sig == SIGUSR2)
			write(1, "\nComplete send message!\n", 25);
		else
			error("\nSend error!!!");
		g_flag = 0;
		g_server_pid = 0;
		exit(0);
	}
}

int	main(int ac, char **argv)
{
	char			*str;
	unsigned int	str_len;
	t_act			act;

	if (ac < 2)
		return (1);
	setup_act(&act, catch_signal);
	g_server_pid = check_pid(argv[1]);
	str = argv[2];
	str_len = (unsigned int)ft_strlen(str);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	send_len(str_len);
	send_message(str, str_len);
	g_flag = 1;
	while (1)
		pause();
	return (0);
}