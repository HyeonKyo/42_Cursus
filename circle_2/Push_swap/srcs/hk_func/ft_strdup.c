#include "push_swap.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (src[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == 0)
		return (0);
	while (++j <= i)
		temp[j] = src[j];
	return (temp);
}
