/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rotate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:55:52 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:55:54 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x(t_map *data, double rad)
{
	int		i;
	t_crd	trans;

	trans.x = 0;
	trans.y = data->map->y / 2;
	trans.z = data->map->z / 2;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	rotate_x_axis(data, rad);
	trans.y *= -1;
	trans.z *= -1;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	isometric_view(data);
}

void	rotate_y(t_map *data, double rad)
{
	int		i;
	t_crd	trans;

	trans.x = data->map->x / 2;
	trans.y = 0;
	trans.z = data->map->z / 2;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	rotate_y_axis(data, rad);
	trans.x *= -1;
	trans.z *= -1;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	isometric_view(data);
}

void	rotate_z(t_map *data, double rad)
{
	int		i;
	t_crd	trans;

	trans.x = data->map->x / 2;
	trans.y = data->map->y / 2;
	trans.z = 0;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	rotate_z_axis(data, rad);
	trans.x *= -1;
	trans.y *= -1;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	isometric_view(data);
}

void	parallel_rotate(t_ptr *ptr, double rad)
{
	int			i;
	t_map		*data;
	t_2d_crd	*crd_2d;
	t_2d_crd	tmp;

	data = ptr->data;
	crd_2d = data->crd_2d;
	i = -1;
	while (++i < data->size)
	{
		tmp.x = crd_2d[i].x - data->map->x / 2;
		tmp.y = crd_2d[i].y - data->map->y / 2;
		crd_2d[i].x = tmp.x * cos(rad) + tmp.y * sin(rad);
		crd_2d[i].y = tmp.y * cos(rad) - tmp.x * sin(rad);
		crd_2d[i].x += data->map->x / 2;
		crd_2d[i].y += data->map->y / 2;
	}
	reprint_map(ptr);
}
