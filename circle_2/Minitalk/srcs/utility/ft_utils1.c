#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	print_num(unsigned int n, int *flag)
{
	char	c;

	if (n == 0 && *flag == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n == 0)
		return ;
	*flag = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	print_num(n / 10, flag);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(unsigned int n)
{
	int	flag;

	flag = 0;
	print_num(n, &flag);
	write(1, "\n", 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ptr;
	while (i < num)
		str[i++] = value;
	return (ptr);
}
