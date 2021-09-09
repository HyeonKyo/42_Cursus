#include "fdf.h"

void	zoom(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		data->crd_2d[i].x *= 2;
		data->crd_2d[i++].y *= 2;
	}
}

void	unzoom(t_map *data)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		data->crd_2d[i].x /= 2;
		data->crd_2d[i++].y /= 2;
	}
}
