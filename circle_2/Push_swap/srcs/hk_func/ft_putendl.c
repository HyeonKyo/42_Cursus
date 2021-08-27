#include "push_swap.h"

void	ft_putendl(char *str, int fd)
{
	ft_putstr(str, fd);
	write(fd, "\n", 1);
}
