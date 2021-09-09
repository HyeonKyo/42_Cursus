#include "fdf.h"

static void	bresenham_init(t_2d_crd start, t_2d_crd end, t_icrd *crd, t_icrd *inc)
{
	crd->x = start.x;
	crd->y = start.y;
	inc->x = 1;
	if (start.x > end.x)
		inc->x = -1;
	inc->y = 1;
	if (start.y > end.y)
		inc->y = -1;
}

void	based_x(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img)
{
	int		f;
	t_icrd	crd;
	t_icrd	inc;

	bresenham_init(start, end, &crd, &inc);
	f = (2 * diff.y) - diff.x;//p의 초기값
	if (start.x <= end.x)
		while (crd.x <= end.x)
		{
			get_color(start, end, &crd, TRUE);
			print_pixel(crd, img);
			if (diff.y == 0)
				crd.x += inc.x;
			else
				get_crd_x(&crd, inc, diff, &f);
		}
	else
		while (crd.x >= end.x)
		{
			get_color(start, end, &crd, TRUE);
			print_pixel(crd, img);
			if (diff.y == 0)
				crd.x += inc.x;
			else
				get_crd_x(&crd, inc, diff, &f);
		}
}

void	based_y(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img)
{
	int		f;
	t_icrd	crd;
	t_icrd	inc;

	bresenham_init(start, end, &crd, &inc);
	f = (2 * diff.x) - diff.y;//p의 초기값
	if (start.y <= end.y)
		while (crd.y <= end.y)
		{
			get_color(start, end, &crd, FALSE);
			print_pixel(crd, img);
			if (diff.x == 0)
				crd.y += inc.y;
			else
				get_crd_y(&crd, inc, diff, &f);
		}
	else
		while (crd.y <= end.y)
		{
			get_color(start, end, &crd, FALSE);
			print_pixel(crd, img);
			if (diff.x == 0)
				crd.y += inc.y;
			else
				get_crd_y(&crd, inc, diff, &f);
		}
}
