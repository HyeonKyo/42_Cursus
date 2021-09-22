#include "fdf.h"

// void	adjust_z(t_map *data)
// {
// 	int	i;
// 	t_crd	scail;
// 	/*
// 	1. eye만큼 translation
// 	2. unit벡터 이용한 rotation
// 	*/
// 	scail.x = 1;
// 	scail.y = 1;
// 	if (data->map->z != 0)
// 		scail.z = (double)(data->map->x) * 5 / (data->map->z * 30);//맵 x길이 20당 최대 z값 = 2;
// 	//map->x / 20 * 3 = map->z * x
// 	i = 0;
// 	scail.z *= -1;//왼손 좌표계로 변환
// 	while (i < data->size)
// 	{
// 		scail_vector(&(data->crd[i]), scail);
// 		i++;
// 	}
// 	data->map->z *= scail.z;
// }

// void	camera_eye(t_crd *eye, t_map *data)
// {
// 	t_map_len	*map;
// 	int	max;

// 	map = data->map;
// 	max = find_max(map->x, map->y, map->z);
// 	max++;
// 	eye->x = (double)max;
// 	eye->y = (double)max;
// 	eye->z = map->z;
// }

// t_crd	make_n_vector(t_crd eye)
// {
// 	t_crd	origin;
// 	t_crd	size;

// 	ft_memset(&origin, 0, sizeof(t_crd));
// 	size.x = 1 / distance_crd(origin, eye);
// 	size.y = size.x;
// 	size.z = size.x;
// 	scail_vector(&eye, size);
// 	return (eye);
// }

// t_crd	make_v_vector(t_crd eye, t_unit *unit)
// {
// 	t_crd	crd;
// 	t_crd	up;
// 	t_crd	size;
// 	double	rad;

// 	rad = atan(eye.z / (eye.x * sqrt(2)));
// 	up.x = -sin(rad);
// 	up.y = up.x;
// 	up.z = cos(rad) * sqrt(2);
// 	crd = cross_vector(up, unit->n);
// 	size.x = 1 / size_crd(crd);
// 	size.y = size.x;
// 	size.z = size.x;
// 	scail_vector(&crd, size);
// 	return (crd);
// }

// void	make_u_vector(t_unit *unit)
// {
// 	unit->u = cross_vector(unit->n, unit->u);
// }

// void	make_camera_unit(t_crd eye, t_unit *unit)
// {
// 	unit->n = make_n_vector(eye);
// 	unit->v = make_v_vector(eye, unit);
// 	make_u_vector(unit);
// }

// void	translate_first_quadrant(t_map *data)
// {
// 	t_crd	trans;
// 	int	i;

// 	trans.x = data->crd[data->map->x * (data->map->y - 1)].x;
// 	trans.y = 0.0;
// 	trans.z = 0.0;
// 	i = 0;
// 	while (i < data->size)
// 	{
// 		translation_vector(&(data->crd[i]), trans);
// 		i++;
// 	}
// }

// void	change_view_to_camera(t_crd eye, t_unit unit, t_map *data)
// {
// 	int	i;
// 	t_crd	scail;
// 	/*
// 	1. eye만큼 translation
// 	2. unit벡터 이용한 rotation
// 	*/
// 	scail.x = 1;
// 	scail.y = 1;
// 	scail.z = 0.15;
// 	i = 0;
// 	while (i < data->size)
// 	{
// 		//scail_vector(&(data->crd[i]), scail);
// 		translation_vector(&(data->crd[i]), eye);
// 		rotate_unit_vector(unit, &(data->crd[i]));
// 		i++;
// 	}
// }

static void	save_min_crd(t_2d_crd crd_2d, t_2d_crd *min)
{
	if (min->x > crd_2d.x)
		min->x = crd_2d.x;
	if (min->y > crd_2d.y)
		min->y = crd_2d.y;
}

static void	translate_iso(t_map *data, double alpha)
{
	t_2d_crd	*crd_2d;
	t_crd		*crd_3d;
	t_2d_crd	min;
	int			i;

	ft_memset(&min, 0, sizeof(t_2d_crd));
	if (data->crd_2d == NULL)
	{
		crd_2d = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
		merror(crd_2d);
		data->crd_2d = crd_2d;
	}
	else
		crd_2d = data->crd_2d;
	crd_3d = data->crd;
	i = -1;
	while (++i < data->size)
	{
		crd_2d[i].x = (crd_3d[i].x - crd_3d[i].y) * cos(alpha);
		crd_2d[i].y = ((crd_3d[i].x + crd_3d[i].y) * sin(alpha)) - crd_3d[i].z;
		crd_2d[i].color.n = crd_3d[i].color.n;
		save_min_crd(crd_2d[i], &min);
	}
	data->min = min;
}

static void	move_to_1quadrant(t_map *data)
{
	t_2d_crd	*crd_2d;
	t_2d_crd	trans;
	int			i;

	crd_2d = data->crd_2d;
	trans = data->min;
	i = -1;
	while (++i < data->size)
	{
		crd_2d[i].x -= trans.x;
		crd_2d[i].y -= trans.y;
	}
}

int	return_color(double cur_z, int max_z)
{
	if (cur_z < (max_z / 3))
		return (COLOR1);
	else if (cur_z < (max_z * 2 / 3))
		return (COLOR2);
	else
		return (COLOR3);
}

static void	put_in_color(t_map *data)
{
	t_crd	*crd;
	int		max_z;
	int		i;

	crd = data->crd;
	max_z = data->map->z;
	i = -1;
	while (++i < data->size)
	{
		if (crd[i].color.n)
			continue ;
		crd[i].color.n = return_color(crd[i].z, max_z);
	}
}

void	isometric_view(t_map *data)
{
	double	alpha;

	alpha = atan(0.5);
	put_in_color(data);
	translate_iso(data, alpha);
	move_to_1quadrant(data);
}
