#include "minitalk.h"
#include "utils.h"


void	len_handler(int sig, siginfo_t *info, void *context)
{
	static t_info	len;
	static int		client_pid;
	static int		i;
	static char		c;
	static int		cnt;

	get_client_pid(&client_pid, info);
	check_incorrect_pid(&client_pid, info);
	if (i < 4)
		bit_masking(&(len.arr[i]), sig);
	else
		bit_masking(&c, sig);
	cnt++;
	if (i < 4 && cnt == 8)
	{
		i++;
		cnt = 0;
	}
	else if (cnt % 8 == 0)
	{
		print_char(c);
		c = 0;
		if (cnt / 8 == len.num)
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR2);
			usleep(500);
			kill(client_pid, SIGUSR2);
			client_pid = -1;
			len.num = 0;
			cnt = 0;
			i = 0;
			return ;
		}
	}
	usleep(100);
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	//pid_t는 언사인드 인트 32비트
	//클라이언트에서 처음 4바이트를 클라이언트 pid값을 보내면
	//서버에서는 최초 클라이언트의 pid값을 알 수 있다.
	pid_t	pid;
	t_act	act;

	pid = getpid();
	ft_putnbr(pid);
	setup_act(&act, len_handler);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
