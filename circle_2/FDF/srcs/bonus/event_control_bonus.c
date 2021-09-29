/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_control_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:55:32 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:55:33 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	reprint_map(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img.img);
	print_map(ptr);
}

void	move_map(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_A)
		left(ptr->data);
	else if (keycode == KEY_D)
		right(ptr->data);
	else if (keycode == KEY_W)
		up(ptr->data);
	else if (keycode == KEY_S)
		down(ptr->data);
	reprint_map(ptr);
}

void	zoom_map(int keycode, t_ptr *ptr)
{
	if (keycode == KEY_Z)
		zoom_in(ptr->data);
	else if (keycode == KEY_X)
		zoom_out(ptr->data);
	reprint_map(ptr);
}

void	parallel_view(t_ptr *ptr, int *flag)
{
	int		i;
	t_map	*data;

	i = 0;
	data = ptr->data;
	if (*flag == FALSE)
	{
		while (i < data->size)
		{
			data->crd_2d[i].x = data->parallel_crd[i].x + 2;
			data->crd_2d[i].y = data->parallel_crd[i].y + 2;
			data->crd_2d[i].color.n = data->parallel_crd[i].color.n;
			i++;
		}
	}
	else
		isometric_view(data);
	*flag ^= TRUE;
	reprint_map(ptr);
}

void	rotate_map(int keycode, t_ptr *ptr, int flag)
{
	double	rad;

	rad = -1 * M_PI_4 / 2;
	if (keycode == KEY_R || keycode == KEY_Y || keycode == KEY_T)
		rad = M_PI_4 / 2;
	if (flag == TRUE)
	{
		if (keycode == KEY_R || keycode == KEY_F)
			parallel_rotate(ptr, rad);
		return ;
	}
	if (keycode == KEY_Y || keycode == KEY_H)
		rotate_x(ptr->data, rad);
	else if (keycode == KEY_T || keycode == KEY_G)
		rotate_y(ptr->data, rad);
	else
		rotate_z(ptr->data, rad);
	reprint_map(ptr);
}
