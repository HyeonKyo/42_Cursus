/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:58:10 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:58:13 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_2d_crd start, t_2d_crd end, t_img *img)
{
	t_icrd	diff;

	diff.x = (int)fabs(end.x - start.x);
	diff.y = (int)fabs(end.y - start.y);
	if (diff.x > diff.y)
		based_x(start, end, diff, img);
	else
		based_y(start, end, diff, img);
}
