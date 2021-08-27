#include "utils.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	mt_atoi(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num);
}

void	sigerror(void)
{
	write(2, "\nSignal error\n", 14);
	exit(1);
}

void	setup_act(t_act *act, void (*handler)(int, siginfo_t *, void *))
{
	sigemptyset(&(act->sa_mask));
	sigaddset(&(act->sa_mask), SIGUSR1);
	sigaddset(&(act->sa_mask), SIGUSR2);
	act->sa_sigaction = handler;
	act->sa_flags = SA_SIGINFO;
}
