#include "fdf_bonus.h"

static void	finish_fdf(t_ptr *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	exit(0);
}

int	key_press(int keycode, t_ptr *ptr)
{
	static int	parallel_flag;

	if (keycode == ESC)
		finish_fdf(ptr);
	else if (keycode == KEY_A || keycode == KEY_D
			|| keycode == KEY_W || keycode == KEY_S)
			move_map(keycode, ptr);
	else if (keycode == KEY_Z || keycode == KEY_X)
		zoom_map(keycode, ptr);
	else if (keycode == KEY_P)
		parallel_view(ptr, &parallel_flag);
	else if (keycode == KEY_Y || keycode == KEY_T || keycode == KEY_R)
		rotate_map(keycode, ptr, parallel_flag);
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
