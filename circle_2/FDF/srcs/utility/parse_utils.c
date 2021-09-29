/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:00:04 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 15:00:05 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_arr(int **arr, t_map_len *map)
{
	int	i;

	i = 0;
	while (i < map->y)
		free(arr[i++]);
	free(arr);
}

void	clear_str(char **buf, char **line)
{
	int	i;

	i = 0;
	while (buf[i][0] != 0)
		free(buf[i++]);
	free(buf[i]);
	free(buf);
	free(*line);
	*line = 0;
}

t_map	*create_data(void)
{
	t_map	*data;

	data = (t_map *)malloc(sizeof(t_map));
	merror(data);
	ft_memset(data, 0, sizeof(t_map));
	data->map = (t_map_len *)malloc(sizeof(t_map_len));
	merror(data->map);
	ft_memset(data->map, 0, sizeof(t_map_len));
	return (data);
}

void	save_parallel_data(t_map *data)
{
	int			i;
	t_2d_crd	*tmp;

	tmp = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
	merror(tmp);
	i = -1;
	while (++i < data->size)
	{
		tmp[i].x = data->crd[i].x;
		tmp[i].y = data->crd[i].y;
		tmp[i].color = data->crd[i].color;
	}
	data->parallel_crd = tmp;
}
