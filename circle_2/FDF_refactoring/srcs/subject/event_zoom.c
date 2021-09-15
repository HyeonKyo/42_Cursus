#include "fdf.h"

void	zoom_in(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 4;
	if (move_len == 0)
		move_len = 3;
	i = 0;
	while (i < data->size)
	{
		data->crd_2d[i].x -= move_len;
		data->crd_2d[i].x *= 1.5;
		data->crd_2d[i].y -= move_len * 3 / 5;
		data->crd_2d[i++].y *= 1.5;
	}
}

void	zoom_out(t_map *data)
{
	int	i;
	int	move_len;

	move_len = data->map->x / 4;
	if (move_len == 0)
		move_len = 3;
	i = 0;
	while (i < data->size)
	{
		data->crd_2d[i].x += move_len + 2;//기준 명확히 하기.
		data->crd_2d[i].x /= 1.5;
		data->crd_2d[i].y += move_len * 2 / 3;
		data->crd_2d[i++].y /= 1.5;
	}
}

void	parallel_view(t_map *data, int *flag)
{
	int	i;

	i = 0;
	if (*flag == FALSE)
	{
		while (i < data->size)
		{
			data->crd_2d[i].x = data->crd[i].x;
			data->crd_2d[i].y = data->crd[i].y;
			i++;
		}
	}
	else
		isometric_view(data);
	*flag ^= TRUE;
}
