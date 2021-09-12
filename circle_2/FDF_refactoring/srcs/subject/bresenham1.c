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
	int		cnt;
	t_icrd	crd;
	t_icrd	inc;

	bresenham_init(start, end, &crd, &inc);
	f = (2 * diff.y) - diff.x;//p의 초기값
	cnt = 0;
	if (start.x <= end.x)
		while (crd.x <= end.x)
		{
			get_color(start, end, &crd, TRUE);
			print_pixel(crd, img);
			if (get_crd_x(&crd, inc, diff, &f))
				anti_aliasing_x(crd, inc, &cnt, img);
			else
				cnt++;
		}
	else
		while (crd.x >= end.x)
		{
			get_color(start, end, &crd, TRUE);
			print_pixel(crd, img);
			if (get_crd_x(&crd, inc, diff, &f))
				anti_aliasing_x(crd, inc, &cnt, img);
			else
				cnt++;
		}
}

void	based_y(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img)
{
	int		f;
	int		cnt;
	t_icrd	crd;
	t_icrd	inc;

	bresenham_init(start, end, &crd, &inc);
	f = (2 * diff.x) - diff.y;//p의 초기값
	cnt = 0;
	if (start.y <= end.y)
		while (crd.y <= end.y)
		{
			get_color(start, end, &crd, FALSE);
			print_pixel(crd, img);
			if (get_crd_y(&crd, inc, diff, &f))
				anti_aliasing_y(crd, inc, &cnt, img);
			else
				cnt++;
		}
	else
		while (crd.y <= end.y)
		{
			get_color(start, end, &crd, FALSE);
			print_pixel(crd, img);
			if (get_crd_y(&crd, inc, diff, &f))
				anti_aliasing_y(crd, inc, &cnt, img);
			else
				cnt++;
		}
}
