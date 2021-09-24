#include "minitalk.h"

void	bit_masking(char *c, int signo)
{
	*c = *c << 1;
	if (signo == SIGUSR2)
		*c |= ADD_BIT;
}

static void	check_incorrect_pid(pid_t *client_pid, siginfo_t *info)
{
	if (info->si_pid != *client_pid)
	{
		while (kill(*client_pid, SIGUSR1) >= 0)
			usleep(10);
		while (kill(info->si_pid, SIGUSR1) >= 0)
			usleep(10);
		*client_pid = -1;
		sigerror();
	}
}

void	get_client_pid(pid_t *client_pid, siginfo_t *info)
{
	if (*client_pid <= 0)//처음 클라이언트 신호를 받을 때
		*client_pid = info->si_pid;
	check_incorrect_pid(client_pid, info);
}
