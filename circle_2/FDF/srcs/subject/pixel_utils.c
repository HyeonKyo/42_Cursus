/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:58:47 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:58:48 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_2d_crd	*multiplied_pixel(t_map *data)
{
	t_2d_crd	*new;
	t_2d_crd	*crd_2d;
	t_2d_crd	mul;
	int			i;

	new = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
	merror(new);
	crd_2d = data->crd_2d;
	mul.x = IMG_X_SIZE / (data->map->x * 1.5);
	mul.y = IMG_Y_SIZE / (data->map->y + data->map->z + 1);
	i = 0;
	while (i < data->size)
	{
		new[i].x = (int)(crd_2d[i].x * mul.x);
		new[i].y = (int)(crd_2d[i].y * mul.y);
		new[i].color.n = crd_2d[i].color.n;
		i++;
	}
	return (new);
}
