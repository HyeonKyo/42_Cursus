#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}
