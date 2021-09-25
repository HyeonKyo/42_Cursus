#include "minitalk.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

void	ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putendl(char *str, int fd)
{
	ft_putstr(str, fd);
	write(fd, "\n", 1);
}

void	setup_act(t_act *act, void (*handler)(int, siginfo_t *, void *))
{
	sigemptyset(&(act->sa_mask));
	sigaddset(&(act->sa_mask), SIGUSR1);
	sigaddset(&(act->sa_mask), SIGUSR2);
	act->sa_sigaction = handler;
	act->sa_flags = SA_SIGINFO;//sa_sigaction에 있는 핸들러를 사용
}
