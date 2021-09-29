/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:21:02 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/25 17:21:04 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	static int	print_cnt;

	bit_masking(&c, sig);
	sig_cnt++;
	if (sig_cnt == 8)
	{
		ft_putchar(c);
		print_cnt++;
		sig_cnt = 0;
		c = 0;
	}
	if (print_cnt == len->num)//다 받았을 때
	{
		write(1, "\n", 1);
		usleep(100);
		kill(client_pid, SIGUSR2);
		usleep(100);
		kill(client_pid, SIGUSR2);
		print_cnt = 0;
		return (0);
	}
	return (1);
}

void	len_handler(int sig, siginfo_t *info, void *context)
{
	static t_info	len;
	static pid_t	client_pid;
	static int		len_idx;
	int				ret;

	context = NULL;
	ret = 1;
	if (get_client_pid(&client_pid, info))//클라이언트 시그널을 계속 확인함.
		sigerror();
	if (len_idx < 4)
		get_strlen(&len, sig, &len_idx);
	else
		ret = get_string(&len, sig, client_pid);
	if (ret == 0)//다 보냈을 때
	{
		len.num = 0;
		len_idx = 0;
		client_pid = -1;
		return ;
	}
	usleep(20);
	if (kill(client_pid, SIGUSR2) < 0)
		sigerror();
}

int	main(void)
{
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
