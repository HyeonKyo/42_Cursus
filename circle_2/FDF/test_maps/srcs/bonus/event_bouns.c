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
			data->crd_2d[i].x = data->parallel_crd[i].x;
			data->crd_2d[i].y = data->parallel_crd[i].y;
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
	static double	angel_z;

	if (flag == TRUE && keycode != KEY_R)
		return ;
	if (keycode == KEY_Y)
		rotate_x(ptr->data);
	else if (keycode == KEY_T)
		rotate_y(ptr->data);
	else
	{
		rotate_z(ptr->data);
		angel_z += M_PI_4 / 2;
	}
	reprint_map(ptr);
}
