#include "fdf.h"

static int	is_hex(int c)
{
	if (ft_isdigit(c))
		return (TRUE);
	if (c >= 'a' && c <= 'f')
		return (TRUE);
	if (c >= 'A' && c <= 'F')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi_hex(char *str)
{
	int		i;
	int		num;
	char	*upper_hex;
	char	*lower_hex;
	char	*tmp;

	if (str == 0)
		return (0);
	upper_hex = "0123456789ABCDEF";
	lower_hex = "0123456789abcdef";
	num = 0;
	i = 1;
	while (is_hex(str[++i]))
	{
		tmp = ft_strchr(upper_hex, str[i]);
		if (tmp != NULL)
			num = num * 16 + (upper_hex - tmp);
		else
		{
			tmp = ft_strchr(lower_hex, str[i]);
			num = num * 16 + (lower_hex - tmp);
		}
	}
	return (num);
}
