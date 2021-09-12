#include "fdf.h"

void	print_data(t_map *data)
{
	printf("data\n");
	for (int i = 0; i < data->size; i++)
	{
		printf("(%.1f %.1f %.1f) ", data->crd[i].x, data->crd[i].y, data->crd[i].z);
		if (i % data->map->x == data->map->x - 1)
			printf("\n");
	}
}

void	print_2d_data(t_map *data)
{
	printf("data\n");
	for (int i = 0; i < data->size; i++)
	{
		printf("(%.1f %.1f) ", data->crd_2d[i].x, data->crd_2d[i].y);
		if (i % data->map->x == data->map->x - 1)
			printf("\n");
	}
}

int		key_press(int keycode, t_ptr *ptr)
{
	static int	flag;

	if (keycode == ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		// system("leaks fdf");
		exit(0);
	}
	else if (keycode == KEY_D)
		right(ptr->data);
	else if (keycode == KEY_A)
		left(ptr->data);
	else if (keycode == KEY_W)
		up(ptr->data);
	else if (keycode == KEY_S)
		down(ptr->data);
	else if (keycode == KEY_Z)
		zoom_in(ptr->data);
	else if (keycode == KEY_X)
		zoom_out(ptr->data);
	else if (keycode == KEY_P)
		parallel_view(ptr->data, &flag);
	reprint_map(ptr);
	return (0);
}

void	print_map(t_ptr *ptr)
{
	t_img	img;

	img.img = mlx_new_image(ptr->mlx, IMG_X_SIZE, IMG_Y_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ptr->img = img;
	print_pixel_in_vector(&img, ptr->data);
	mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, 100, 50);
	mlx_hook(ptr->win, 2, 1L<<0, &key_press, ptr);
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
	/*
	3. 화면 출력(print_iso)
		1. 일련의 과정 수행
		2. 반복문으로 iso벡터의 점들 z값 제외해서 찍어줌
		3. 출력.
	*/
	return (0);
}
