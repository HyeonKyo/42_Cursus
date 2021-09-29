/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_zoom_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:55:59 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:56:02 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom_in(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 4;
	if (move_len == 0)
		move_len = 3;
	i = 0;
	while (i < data->size)
	{
		data->crd_2d[i].x -= move_len;
		data->crd_2d[i].x *= 1.5;
		data->crd_2d[i].y -= move_len * 3 / 5;
		data->crd_2d[i++].y *= 1.5;
	}
}

void	zoom_out(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 4;
	if (move_len == 0)
		move_len = 3;
	i = 0;
	while (i < data->size)
	{
		data->crd_2d[i].x += move_len + 2;
		data->crd_2d[i].x /= 1.5;
		data->crd_2d[i].y += move_len * 2 / 3;
		data->crd_2d[i++].y /= 1.5;
	}
}
