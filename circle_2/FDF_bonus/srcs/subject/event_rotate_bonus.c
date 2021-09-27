#include "fdf.h"

void	rotate_x(t_map *data)
{
	int		i;
	double	rad;
	t_crd	trans;

	rad = M_PI_4 / 2;
	trans.x = 0;
	trans.y = data->map->y / 2;
	trans.z = data->map->z / 2;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	rotate_x_axis(data, rad);
	trans.y *= -1;
	trans.z *= -1;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	isometric_view(data);
}

void	rotate_y(t_map *data)
{
	int		i;
	double	rad;
	t_crd	trans;

	rad = M_PI_4 / 2;
	trans.x = data->map->x / 2;
	trans.y = 0;
	trans.z = data->map->z / 2;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	rotate_y_axis(data, rad);
	trans.x *= -1;
	trans.z *= -1;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	isometric_view(data);
}

void	rotate_z(t_map *data)
{
	int		i;
	double	rad;
	t_crd	trans;

	rad = M_PI_4 / 2;
	trans.x = data->map->x / 2;
	trans.y = data->map->y / 2;
	trans.z = 0;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	rotate_z_axis(data, rad);
	trans.x *= -1;
	trans.y *= -1;
	i = 0;
	while (i < data->size)
		translation_vector(&(data->crd[i++]), trans);
	isometric_view(data);
}
