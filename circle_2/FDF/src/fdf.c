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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_2d_crd	*multiplied_pixel(t_map *data)
{
	t_2d_crd	*crd2;
	t_2d_crd	mul;
	size_t	i;

	mul.x = IMG_X_SIZE / data->map->x;
	mul.y = IMG_Y_SIZE / data->map->y;
	//mul.x = 40;
	//mul.y = 40;
	crd2 = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
	i = 0;
	while (i < data->size)
	{
		crd2[i].x = data->crd[i].x * mul.x;
		crd2[i].y = data->crd[i].y * mul.y;
		i++;
	}
	return (crd2);
}

void	based_x(t_2d_crd start, t_2d_crd end, t_delta *diff, t_img *img)
{
	int	p;
	t_2d_crd	crd;
	t_2d_crd	inc;
	int	x;
	int	y;

	crd.x = start.x;
	crd.y = start.y;
	inc.x = 1;
	if (start.x > end.x)
		inc.x = -1;
	inc.y = 1;
	if (start.y > end.y)
		inc.y = -1;
	p = 2 * (diff->y - diff->x);//p의 초기값
	if (diff->y == 0)
	{
		while (start.x <= end.x ? crd.x <= end.x : crd.x >= end.x)
		{
			if (crd.x < IMG_X_SIZE && crd.y < IMG_Y_SIZE && crd.x >= 0 && crd.y >= 0)
				my_mlx_pixel_put(img, crd.x, crd.y, GR);
			crd.x += inc.x;
		}
		return ;
	}
	while (start.x <= end.x ? crd.x <= end.x : crd.x >= end.x)
	{
		if (crd.x < IMG_X_SIZE && crd.y < IMG_Y_SIZE && crd.x >= 0 && crd.y >= 0)
			my_mlx_pixel_put(img, crd.x, crd.y, GR);
		crd.x += inc.x;
		if (p >= 0)
		{
			crd.y += inc.y;
			p += 2 * (diff->y - diff->x);
		}
		else
			p += 2 * diff->y;
	}
}

void	based_y(t_2d_crd start, t_2d_crd end, t_delta *diff, t_img *img)
{
	int	p;
	t_2d_crd	crd;
	t_2d_crd	inc;

	crd.x = start.x;
	crd.y = start.y;
	inc.x = 1;
	if (start.x > end.x)
		inc.x = -1;
	inc.y = 1;
	if (start.y > end.y)
		inc.y = -1;
	p = 2 * (diff->x - diff->y);//p의 초기값
	if (diff->x == 0)
	{
		while (start.y <= end.y ? crd.y <= end.y : crd.y >= end.y)
		{
			if (crd.x < IMG_X_SIZE && crd.y < IMG_Y_SIZE && crd.x >= 0 && crd.y >= 0)
				my_mlx_pixel_put(img, crd.x, crd.y, GR);
			crd.y += inc.y;
		}
		return ;
	}
	while (start.y <= end.y ? crd.y <= end.y : crd.y >= end.y)
	{
		if (crd.x < IMG_X_SIZE && crd.y < IMG_Y_SIZE && crd.x >= 0 && crd.y >= 0)
			my_mlx_pixel_put(img, crd.x, crd.y, GR);
		crd.y += inc.y;
		if (p >= 0)
		{
			crd.x += inc.x;
			p += 2 * (diff->x - diff->y);
		}
		else
			p += 2 * diff->x;
	}
}

//맨처음 start점은 임의로 찍어주고 나머지 모든 점,선은 bresenham함수 반복으로 찍어줌.
//start에 vec[0]넣어주고 나머지는 반복문으로 넣어줌
void	bresenham(t_2d_crd start, t_2d_crd end, t_img *img)
{
	t_delta	diff;

	diff.x = abs(end.x - start.x);
	diff.y = abs(end.y - start.y);
	if (diff.x >= diff.y)
		based_x(start, end, &diff, img);
	else
		based_y(start, end, &diff, img);
}

void	print_pixel_in_vector(t_img *img, t_map *data)
{
	/*
	1. iso_data에 mul_x, mul_y를 곱해주기
	2. 2점씩 골라서 bresenham함수로 선 하나씩 그려주기
		1. dx, dy의 차이에 따른 함수 구분
		2. dx가 크다면 -> based_x
			1. inc.x = 1, inc.y = 1(start, end의 값에 따라 -1)
			2. p의 초기값 = 2dy - dx
			3. 초기 x, y = start의 x, y값
			--반복문 시작--
			4. 다음 x, y값은 x + 1, y값은 p에 따라 달라짐
				p >= 0이면 y + 1, p < 0이면 y그대로
			5. 다음 p값 구함
				p >= 0이면 p = p + 2dy -2dx
				p < 0이면 p = p + 2dy
	3. 2번 반복문 돌리기(vec[i] i++하면서)
		4. 만약 i = map->x - 1이면 아래쪽 선만 그리기
		5. 일반적으론 i+1과 i+map->x벡터와 이어주기
		6. i가 map->x * (map->y - 1)부터는 오른쪽과만 이어주기
	*/
	size_t	i;
	t_2d_crd	*crd2;
	t_map_len	*map;

	crd2 = multiplied_pixel(data);
	map = data->map;
	i = 0;
	while (i < data->size - 1)
	{
		if (i < map->x * (map->y - 1))
			bresenham(crd2[i], crd2[i + map->x], img);
		if (i % map->x != map->x - 1)
			bresenham(crd2[i], crd2[i + 1], img);
		i++;
	}
	free(crd2);
}

int		key_press(int keycode, t_ptr *ptr)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
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
		zoom(ptr->data);
	else if (keycode == KEY_X)
		unzoom(ptr->data);
	reprint_map(ptr);
	return (0);
}

void	print_map(t_ptr *ptr)
{
	t_img	img;

	img.img = mlx_new_image(ptr->mlx, IMG_X_SIZE * 1.5, IMG_Y_SIZE * 1.5);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ptr->img = img;
	print_pixel_in_vector(&img, ptr->data);
	print_data(ptr->data);
	mlx_put_image_to_window(ptr->mlx, ptr->win, img.img, 50, 50);
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
	make_iso_vector(data);
	make_graphic(data);
	/*
	3. 화면 출력(print_iso)
		1. 일련의 과정 수행
		2. 반복문으로 iso벡터의 점들 z값 제외해서 찍어줌
		3. 출력.
	*/
	return (0);
}
