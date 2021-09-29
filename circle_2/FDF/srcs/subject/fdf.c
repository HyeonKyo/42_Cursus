/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:58:21 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:58:23 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	finish_fdf(t_ptr *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
}

int	key_press(int keycode, t_ptr *ptr)
{
	if (keycode == ESC)
		finish_fdf(ptr);
	return (0);
}

void	print_map(t_ptr *ptr)
{
	t_img	img;

	img.img = mlx_new_image(ptr->mlx, IMG_X_SIZE, IMG_Y_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	ptr->img = img;
	print_pixel_in_vector(&img, ptr->data);
	mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, 0, 0);
	mlx_hook(ptr->win, 2, 1L << 0, &key_press, ptr);
	mlx_loop(ptr->mlx);
}

void	make_graphic(t_map *data)
{
	t_ptr	ptr;

	make_ptr(&ptr, data);
	print_map(&ptr);
}

int	main(int ac, char **av)
{
	t_map	*data;

	data = parsing_map(ac, av);
	isometric_view(data);
	make_graphic(data);
	return (0);
}
