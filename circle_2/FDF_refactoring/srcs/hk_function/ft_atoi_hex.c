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
	int		len;
	char	*hex;
	char	*tmp;

	if (str == 0)
		return (0);
	i = 1;
	len = (int)ft_strlen(str);
	hex = "0123456789ABCDEF0123456789abcdef";
	num = 0;
	while (++i < len)
	{
		if (!is_hex(str[i]))
			break ;
		tmp = ft_strchr(hex, str[i]);
		if (tmp != NULL)
			num = num * 16 + ((tmp - hex) % 16);
		else
		{
			tmp = ft_strchr(hex, str[i]);
			num = num * 16 + ((tmp - hex) % 16);
		}
	}
	return (num);
}
