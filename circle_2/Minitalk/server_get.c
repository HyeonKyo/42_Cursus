#include "minitalk.h"
#include "utils.h"

void	bit_masking(char *c, int signo)
{
	*c = *c << 1;
	if (signo == SIGUSR2)
		*c |= ADD_BIT;
}

void	get_client_pid(pid_t *client_pid, siginfo_t *info)
{
	if (*client_pid <= 0)
		*client_pid = info->si_pid;
}

void	check_incorrect_pid(pid_t *client_pid, siginfo_t *info)
{
	if (info->si_pid != *client_pid)
	{
		kill(*client_pid, SIGUSR1);
		kill(info->si_pid, SIGUSR1);
		*client_pid = 0;
		sigerror();
	}
}
