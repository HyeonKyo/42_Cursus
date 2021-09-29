/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:59:21 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:59:23 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	save_min_crd(t_2d_crd crd_2d, t_2d_crd *min)
{
	if (min->x > crd_2d.x)
		min->x = crd_2d.x;
	if (min->y > crd_2d.y)
		min->y = crd_2d.y;
}

static void	translate_iso(t_map *data, double alpha)
{
	t_2d_crd	*crd_2d;
	t_crd		*crd_3d;
	t_2d_crd	min;
	int			i;

	ft_memset(&min, 0, sizeof(t_2d_crd));
	if (data->crd_2d == NULL)
	{
		crd_2d = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
		merror(crd_2d);
		data->crd_2d = crd_2d;
	}
	else
		crd_2d = data->crd_2d;
	crd_3d = data->crd;
	i = -1;
	while (++i < data->size)
	{
		crd_2d[i].x = (crd_3d[i].x - crd_3d[i].y) * cos(alpha);
		crd_2d[i].y = ((crd_3d[i].x + crd_3d[i].y) * sin(alpha)) - crd_3d[i].z;
		crd_2d[i].color.n = crd_3d[i].color.n;
		save_min_crd(crd_2d[i], &min);
	}
	data->min = min;
}

static void	move_to_1quadrant(t_map *data)
{
	t_2d_crd	*crd_2d;
	t_2d_crd	trans;
	int			i;

	crd_2d = data->crd_2d;
	trans = data->min;
	i = -1;
	while (++i < data->size)
	{
		crd_2d[i].x -= trans.x;
		crd_2d[i].y -= trans.y;
	}
}

void	isometric_view(t_map *data)
{
	double	alpha;

	alpha = atan(0.5);
	translate_iso(data, alpha);
	move_to_1quadrant(data);
}
