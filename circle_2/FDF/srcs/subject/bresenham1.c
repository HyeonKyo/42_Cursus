/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:58:56 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:58:58 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bresenham_init(t_2d_crd st, t_2d_crd end, t_icrd *crd, t_icrd *inc)
{
	crd->x = st.x;
	crd->y = st.y;
	inc->x = 1;
	if (st.x > end.x)
		inc->x = -1;
	inc->y = 1;
	if (st.y > end.y)
		inc->y = -1;
}

void	based_x(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img)
{
	int		f;
	int		cnt;
	t_icrd	crd;
	t_icrd	inc;

	bresenham_init(start, end, &crd, &inc);
	f = (2 * diff.y) - diff.x;
	cnt = 0;
	while ((start.x <= end.x) ^ (crd.x > end.x))
	{
		get_color(start, end, &crd, TRUE);
		print_pixel(crd, img);
		if (get_crd_x(&crd, inc, diff, &f))
			anti_aliasing_x(crd, inc, &cnt, img);
		else
			cnt++;
	}
}

void	based_y(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img)
{
	int		f;
	int		cnt;
	t_icrd	crd;
	t_icrd	inc;

	bresenham_init(start, end, &crd, &inc);
	f = (2 * diff.x) - diff.y;
	cnt = 0;
	while ((start.y <= end.y) ^ (crd.y > end.y))
	{
		get_color(start, end, &crd, FALSE);
		print_pixel(crd, img);
		if (get_crd_y(&crd, inc, diff, &f))
			anti_aliasing_y(crd, inc, &cnt, img);
		else
			cnt++;
	}
}
