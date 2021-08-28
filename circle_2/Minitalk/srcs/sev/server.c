#include "minitalk.h"

static void	get_strlen(t_info *len, int sig, int *len_idx)
{
	static int	sig_cnt;

	bit_masking(&(len->arr[*len_idx]), sig);//처음 32개의 비트는 받을 문자열의 길이를 받음
	sig_cnt++;
	if (sig_cnt == 8)
	{
		(*len_idx)++;
		sig_cnt = 0;
	}
}

static int	get_string(t_info *len, int sig, int client_pid)
{
	static char	c;
	static int	sig_cnt;

	bit_masking(&c, sig);
	sig_cnt++;
	if (sig_cnt % 8 == 0)
	{
		print_char(c);
		c = 0;
	}
	if (sig_cnt / 8 == len->num)//다 받았을 때
	{
		write(1, "\n", 1);
		kill(client_pid, SIGUSR2);
		usleep(500);
		kill(client_pid, SIGUSR2);
		sig_cnt = 0;
		return (0);
	}
	usleep(100);
	kill(client_pid, SIGUSR2);
	return (1);
}

void	len_handler(int sig, siginfo_t *info, void *context)
{
	static t_info	len;
	static int		client_pid;
	static int		len_idx;
	int				ret;

	if (context == NULL)
		return ;
	ret = 0;
	get_client_pid(&client_pid, info);//클라이언트 시그널을 계속 확인함.
	if (len_idx < 4)
		get_strlen(&len, sig, &len_idx);
	else
		ret = get_string(&len, sig, client_pid);
	if (ret == 0)
	{
		len.num = 0;
		len_idx = 0;
		client_pid = -1;
		return ;
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
	setup_act(&act, len_handler);//act변수에 handler함수 등록
	sigaction(SIGUSR1, &act, 0);//시그널 받으면 act안의 핸들러 실행
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();//시그널 대기
	return (0);
}
