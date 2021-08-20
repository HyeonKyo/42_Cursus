/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 14:42:31 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:32 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <unistd.h>
# include <stdlib.h>

//utils1
int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);

//utils2
void	*ft_memset(void *ptr, int value, size_t num);
int		ft_strcmp(char *s1, const char *s2);
void	swap_number(int *a, int *b);
void	error(void);
void	merror(void);
#endif