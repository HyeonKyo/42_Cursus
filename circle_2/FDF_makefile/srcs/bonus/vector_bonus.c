#include "fdf_bonus.h"

void	rotate_z_axis(t_map *data, double rad)
{
	int		i;
	t_crd	*vec;
	t_crd	crd;

	vec = data->crd;
	i = 0;
	while (i < data->size)
	{
		crd.x = vec[i].x;
		crd.y = vec[i].y;
		vec[i].x = crd.x * cos(rad) + crd.y * sin(rad);
		vec[i].y = crd.y * cos(rad) - crd.x * sin(rad);
		i++;
	}
}

void	rotate_x_axis(t_map *data, double rad)
{
	int		i;
	t_crd	*vec;
	t_crd	crd;

	vec = data->crd;
	i = 0;
	while (i < data->size)
	{
		crd.y = vec[i].y;
		crd.z = vec[i].z;
		vec[i].y = cos(rad) * crd.y + sin(rad) * crd.z;
		vec[i].z = cos(rad) * crd.z - sin(rad) * crd.y;
		i++;
	}
}

void	rotate_y_axis(t_map *data, double rad)
{
	int		i;
	t_crd	*vec;
	t_crd	crd;

	vec = data->crd;
	i = 0;
	while (i < data->size)
	{
		crd.x = vec[i].x;
		crd.z = vec[i].z;
		vec[i].x = cos(rad) * crd.x - sin(rad) * crd.z;
		vec[i].z = sin(rad) * crd.x + cos(rad) * crd.z;
		i++;
	}
}

void	translation_vector(t_crd *crd, t_crd trans)
{
	crd->x -= trans.x;
	crd->y -= trans.y;
	crd->z -= trans.z;
}
