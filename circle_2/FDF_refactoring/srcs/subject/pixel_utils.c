#include "fdf.h"

t_2d_crd	*multiplied_pixel(t_map *data)
{
	t_2d_crd	*new;
	t_2d_crd	*crd_2d;
	t_2d_crd	mul;
	int			i;

	new = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
	merror(new);
	crd_2d = data->crd_2d;
	mul.x = IMG_X_SIZE / crd_2d[data->map->x - 1].x;//iso뷰에서 가장 큰 x값임.
	mul.y = IMG_Y_SIZE / (data->map->y + data->map->z + 1);//기준 더 명확히 하기
	i = 0;
	while (i < data->size)
	{
		new[i].x = (int)(crd_2d[i].x * mul.x);
		new[i].y = (int)(crd_2d[i].y * mul.y);
		new[i].color.n = crd_2d[i].color.n;
		i++;
	}
	return (new);
}

void	print_pixel_in_vector(t_img *img, t_map *data)
{
	/*
	1. iso_data에 mul_x, mul_y를 곱해주기
	2. 2점씩 골라서 bresenham함수로 선 하나씩 그려주기
		1. dx, dy의 차이에 따른 함수 구분
		2. dx가 크다면 -> based_x
			1. inc.x = 1, inc.y = 1(start, end의 값에 따라 -1)
			2. p의 초기값 = 2dy - dx
			3. 초기 x, y = start의 x, y값
			--반복문 시작--
			4. 다음 x, y값은 x + 1, y값은 p에 따라 달라짐
				p >= 0이면 y + 1, p < 0이면 y그대로
			5. 다음 p값 구함
				p >= 0이면 p = p + 2dy -2dx
				p < 0이면 p = p + 2dy
	3. 2번 반복문 돌리기(vec[i] i++하면서)
		4. 만약 i = map->x - 1이면 아래쪽 선만 그리기
		5. 일반적으론 i+1과 i+map->x벡터와 이어주기
		6. i가 map->x * (map->y - 1)부터는 오른쪽과만 이어주기
	*/
	int		i;
	t_2d_crd	*crd_2d;
	t_map_len	*map;

	crd_2d = multiplied_pixel(data);
	map = data->map;
	i = 0;
	while (i < data->size)
	{
		if (i < map->x * (map->y - 1))
			bresenham(crd_2d[i], crd_2d[i + map->x], img);
		if (i % map->x != map->x - 1)
			bresenham(crd_2d[i], crd_2d[i + 1], img);
		i++;
	}
	free(crd_2d);
}
