/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:57:25 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:57:27 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
