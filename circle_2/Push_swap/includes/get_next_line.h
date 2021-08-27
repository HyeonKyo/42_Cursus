/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkyokim <hyeonkyokim@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:20:20 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/08/23 15:24:54 by hyeonkyokim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 4
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void	ft_bzero(void *ptr, size_t size);
size_t	ft_strlen(const char *str);
int		gnl_strmove(int fd, char **backup, char *src);
char	*ft_strchr(char *str, int c);
char	*gnl_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);

#endif
