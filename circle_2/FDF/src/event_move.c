#include "fdf.h"

void	reprint_map(t_ptr *ptr)
{
	mlx_destroy_image(ptr->mlx, ptr->img.img);
	print_map(ptr);
}

void	right(t_map *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
		data->crd[i++].x -= 1;
	printf("--right--\n");
}

void	left(t_map *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
		data->crd[i++].x += 1;
	printf("--left--\n");
}

void	up(t_map *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
		data->crd[i++].y += 1;
	printf("--up--\n");
}

void	down(t_map *data)
{
	size_t	i;

	i = 0;
	while (i < data->size)
		data->crd[i++].y -= 1;
	printf("--down--\n");
}
