#include "fdf.h"

void	adjust_z(t_map *data)
{
	size_t	i;
	t_crd	scail;
	/*
	1. eye만큼 translation
	2. unit벡터 이용한 rotation
	*/
	scail.x = 1;
	scail.y = 1;
	if (data->map->z != 0)
		scail.z = (double)(data->map->x) * 5 / (data->map->z * 30);//맵 x길이 20당 최대 z값 = 2;
	//map->x / 20 * 3 = map->z * x
	i = 0;
	scail.z *= -1;//왼손 좌표계로 변환
	while (i < data->size)
	{
		scail_vector(&(data->crd[i]), scail);
		i++;
	}
	data->map->z *= scail.z;
}

void	camera_eye(t_crd *eye, t_map *data)
{
	t_map_len	*map;
	int	max;

	map = data->map;
	max = find_max(map->x, map->y, map->z);
	max++;
	eye->x = (double)max;
	eye->y = (double)max;
	eye->z = map->z;
}

t_crd	make_n_vector(t_crd eye)
{
	t_crd	origin;
	t_crd	size;

	ft_memset(&origin, 0, sizeof(t_crd));
	size.x = 1 / distance_crd(origin, eye);
	size.y = size.x;
	size.z = size.x;
	scail_vector(&eye, size);
	return (eye);
}

t_crd	make_v_vector(t_crd eye, t_unit *unit)
{
	t_crd	crd;
	t_crd	up;
	t_crd	size;
	double	rad;

	rad = atan(eye.z / (eye.x * sqrt(2)));
	up.x = -sin(rad);
	up.y = up.x;
	up.z = cos(rad) * sqrt(2);
	crd = cross_vector(up, unit->n);
	size.x = 1 / size_crd(crd);
	size.y = size.x;
	size.z = size.x;
	scail_vector(&crd, size);
	return (crd);
}

void	make_u_vector(t_unit *unit)
{
	unit->u = cross_vector(unit->n, unit->u);
}

void	make_camera_unit(t_crd eye, t_unit *unit)
{
	unit->n = make_n_vector(eye);
	unit->v = make_v_vector(eye, unit);
	make_u_vector(unit);
}

void	translate_first_quadrant(t_map *data)
{
	t_crd	trans;
	size_t	i;

	trans.x = data->crd[data->map->x * (data->map->y - 1)].x;
	trans.y = 0.0;
	trans.z = 0.0;
	i = 0;
	while (i < data->size)
	{
		translation_vector(&(data->crd[i]), trans);
		i++;
	}
}

void	change_view_to_camera(t_crd eye, t_unit unit, t_map *data)
{
	size_t	i;
	t_crd	scail;
	/*
	1. eye만큼 translation
	2. unit벡터 이용한 rotation
	*/
	scail.x = 1;
	scail.y = 1;
	scail.z = 0.15;
	i = 0;
	while (i < data->size)
	{
		//scail_vector(&(data->crd[i]), scail);
		translation_vector(&(data->crd[i]), eye);
		rotate_unit_vector(unit, &(data->crd[i]));
		i++;
	}
}

void	make_iso_vector(t_map *data)
{
	// t_crd	eye;
	// t_unit	unit;
	// /*
	// 1. 카메라 eye포인트 찾기
	// camera_eye(&eye, origin_data);
	// 2. eye와 at(원점)으로 단위벡터 만들기
	// camera_unit(eye, &unit);
	// 3. eye만큼 data translation
	// 4. unit벡터만큼 rotate
	// change_view_to_camera(eye, unit, origin_data);
	// */
	adjust_z(data);
	// camera_eye(&eye, data);
	// make_camera_unit(eye, &unit);
	// change_view_to_camera(eye, unit, data);
	rotate_x_axis(data, M_PI_2 * 2 / 9);
	rotate_z_axis(data, -M_PI_2 / 3);
	rotate_y_axis(data, -M_PI_2 * 1.5 / 9);
	translate_first_quadrant(data);
}
