#include "fdf_bonus.h"

static void	reprint_map(t_ptr *ptr)
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

void	parallel_rotate(t_ptr *ptr)
{
	int			i;
	double		rad;
	t_map		*data;
	t_2d_crd	*crd_2d;
	t_2d_crd	tmp;

	rad = M_PI_4 / 2;
	data = ptr->data;
	crd_2d = data->crd_2d;
	i = -1;
	while (++i < data->size)
	{
		tmp.x = crd_2d[i].x - data->map->x / 2;
		tmp.y = crd_2d[i].y - data->map->y / 2;
		crd_2d[i].x = tmp.x * cos(rad) + tmp.y * sin(rad);
		crd_2d[i].y = tmp.y * cos(rad) - tmp.x * sin(rad);
		crd_2d[i].x += data->map->x / 2;
		crd_2d[i].y += data->map->y / 2;
	}
	reprint_map(ptr);
}

void	rotate_map(int keycode, t_ptr *ptr, int flag)
{
	if (flag == TRUE)
	{
		if (keycode == KEY_R)
			parallel_rotate(ptr);
		return ;
	}
	if (keycode == KEY_Y)
		rotate_x(ptr->data);
	else if (keycode == KEY_T)
		rotate_y(ptr->data);
	else
		rotate_z(ptr->data);
	reprint_map(ptr);
}
