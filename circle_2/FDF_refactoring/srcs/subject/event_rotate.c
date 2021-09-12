#include "fdf.h"

void	rotate(t_map *data)
{
	double	rad;

	rad = M_PI_4 / 2;
	rotate_z_axis(data, rad);
	isometric_view(data);
}