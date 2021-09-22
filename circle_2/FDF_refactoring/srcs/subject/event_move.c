#include "fdf.h"

void	reprint_map(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img.img);
	print_map(ptr);
}

void	right(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 10;
	if (move_len == 0)
		move_len = 1;
	i = -1;
	while (++i < data->size)
		data->crd_2d[i].x -= move_len;
}

void	left(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 10;
	if (move_len == 0)
		move_len = 1;
	i = -1;
	while (++i < data->size)
		data->crd_2d[i].x += move_len;
}

void	up(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->y / 10;
	if (move_len == 0)
		move_len = 1;
	i = 0;
	while (i < data->size)
		data->crd_2d[i++].y += move_len;
}

void	down(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->y / 10;
	if (move_len == 0)
		move_len = 1;
	i = 0;
	while (i < data->size)
		data->crd_2d[i++].y -= move_len;
}
