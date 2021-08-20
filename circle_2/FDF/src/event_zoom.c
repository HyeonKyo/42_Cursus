#include "fdf.h"

void	zoom(t_map *data)
{
	size_t	i;

	printf("--zoom--\n");
	i = 0;
	while (i < data->size)
	{
		data->crd[i].x *= 2;
		data->crd[i++].y *= 2;
	}
}

void	unzoom(t_map *data)
{
	size_t	i;

	printf("--unzoom--\n");
	i = 0;
	while (i < data->size)
	{
		data->crd[i].x /= 2;
		data->crd[i++].y /= 2;
	}
}
