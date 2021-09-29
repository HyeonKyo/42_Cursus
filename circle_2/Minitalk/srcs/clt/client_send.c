/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:20:49 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/25 17:20:50 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_len(int str_len)
{
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	info.num = str_len;
	send_message(info.arr, 4);
}

static void	send_bit(char c, int mask_num)
{
	int	ret;
	int	bit_mask;

	bit_mask = return_mask_number(mask_num);
	ret = 0;
	if (c & bit_mask)
		ret = kill(g_server_pid, SIGUSR2);
	else
		ret = kill(g_server_pid, SIGUSR1);
	if (ret < 0)//시그널을 보낸 프로세스가 없을 때 등.
		sigerror();
}

static void	send_eight_bits(char c)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		send_bit(c, i--);
		pause();
		usleep(20);
	}
}

void	send_message(char *str, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		send_eight_bits(str[i]);
}

void	end_signal(int sig)
{
	if (sig == SIGUSR2)
		write(STDOUT_FILENO, "\nComplete send message!\n", 25);
	else
		error("\nSend error!!\n");
	exit(0);
}

void	send_string(char *str, int len, t_act *act)
{
	send_message(str, len);
	act->sa_handler = end_signal;
	act->sa_flags = 0;
	sigaction(SIGUSR1, act, 0);
	sigaction(SIGUSR2, act, 0);
	pause();
}
