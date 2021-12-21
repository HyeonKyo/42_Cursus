/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:59:09 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:59:13 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	mix_color(t_color color1, t_color color2, double per)
{
	t_uchar	red;
	t_uchar	green;
	t_uchar	blue;
	t_color	c;

	c.n = 0;
	red = (t_uchar)(color1.c[2] * (1 - per) + color2.c[2] * per);
	green = (t_uchar)(color1.c[1] * (1 - per) + color2.c[1] * per);
	blue = (t_uchar)(color1.c[0] * (1 - per) + color2.c[0] * per);
	c.c[2] = red;
	c.c[1] = green;
	c.c[0] = blue;
	c.c[3] = TRANSPARENCY1;
	return (c.n);
}

void	get_color(t_2d_crd start, t_2d_crd end, t_icrd *crd, int flag)
{
	t_color	color1;
	t_color	color2;
	double	per;

	if (start.color.n == end.color.n)
		crd->color.n = start.color.n;
	else
	{
		if (flag == TRUE)
			per = (crd->x - start.x) / (end.x - start.x);
		else
			per = (crd->y - start.y) / (end.y - start.y);
		color1.n = start.color.n;
		color2.n = end.color.n;
		crd->color.n = mix_color(color1, color2, per);
	}
}

int	get_crd_x(t_icrd *crd, t_icrd inc, t_icrd diff, int *f)
{
	crd->x += inc.x;
	if (diff.y == 0)
		return (0);
	if (*f >= 0)
	{
		crd->y += inc.y;
		*f += 2 * (diff.y - diff.x);
		return (1);
	}
	else
		*f += 2 * diff.y;
	return (0);
}

int	get_crd_y(t_icrd *crd, t_icrd inc, t_icrd diff, int *f)
{
	crd->y += inc.y;
	if (diff.x == 0)
		return (0);
	if (*f >= 0)
	{
		crd->x += inc.x;
		*f += 2 * (diff.x - diff.y);
		return (1);
	}
	else
		*f += 2 * diff.x;
	return (0);
}
