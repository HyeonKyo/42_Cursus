#include "fdf.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_pixel(t_icrd crd, t_img *img)
{
	if (crd.x < IMG_X_SIZE && crd.y < IMG_Y_SIZE
		&& crd.x >= 0 && crd.y >= 0)
		my_mlx_pixel_put(img, crd.x, crd.y, crd.color.n);
	//컬러 선정
	/*
	1. 시작 컬러를 준거로 삼음
	2. 컬러가 같으면? 그냥 그 컬러로 찍음
	3. 컬러가 다르면 퍼센테이지 구해서 색 조합
	*/
	//my pixel put
}
