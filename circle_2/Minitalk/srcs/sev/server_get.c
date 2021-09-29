/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 17:21:11 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/25 17:21:12 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_masking(char *c, int signo)
{
	*c = *c << 1;
	if (signo == SIGUSR2)
		*c |= ADD_BIT;
}

static int	check_incorrect_pid(pid_t *client_pid, siginfo_t *info)
{
	if (info->si_pid != *client_pid)
	{
		usleep(20);
		kill(info->si_pid, SIGUSR1);
		usleep(20);
		kill(*client_pid, SIGUSR1);
		*client_pid = -1;
		return (1);
	}
	return (0);
}

int	get_client_pid(pid_t *client_pid, siginfo_t *info)
{
	if (*client_pid <= 0)//처음 클라이언트 신호를 받을 때
		*client_pid = info->si_pid;
	if (check_incorrect_pid(client_pid, info))
		return (1);
	return (0);
}
