char	*ft_strchr(char *str, int c)
{
	int	i;

	i = -1;
	if (str == 0)
		return (0);
	while (str[++i])
		if (str[i] == c)
			return (str + i);
	if (str[i] == 0 && c == 0)
		return (str + i);
	return (0);
}
