/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:53:05 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:55:47 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	right(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 10;
	if (move_len == 0)
		move_len = 1;
	i = -1;
	while (++i < data->size)
		data->crd_2d[i].x -= move_len;
}

void	left(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 10;
	if (move_len == 0)
		move_len = 1;
	i = -1;
	while (++i < data->size)
		data->crd_2d[i].x += move_len;
}

void	up(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->y / 10;
	if (move_len == 0)
		move_len = 1;
	i = 0;
	while (i < data->size)
		data->crd_2d[i++].y += move_len;
}

void	down(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->y / 10;
	if (move_len == 0)
		move_len = 1;
	i = 0;
	while (i < data->size)
		data->crd_2d[i++].y -= move_len;
}
