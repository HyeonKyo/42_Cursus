#include "fdf.h"

static void	anti_aliasing_x_init(t_icrd crd, t_icrd inc, t_icrd *c1, t_icrd *c2)
{
	*c1 = crd;
	*c2 = crd;
	(*c1).color.c[0] += TRANSPARENCY1;
	(*c2).color.c[0] += TRANSPARENCY1;
	if (inc.y > 0)
		(*c2).y--;
	else
		(*c2).y++;
}

static void	anti_aliasing_y_init(t_icrd crd, t_icrd inc, t_icrd *c1, t_icrd *c2)
{
	*c1 = crd;
	*c2 = crd;
	(*c1).color.c[0] += TRANSPARENCY1;
	(*c2).color.c[0] += TRANSPARENCY1;
	if (inc.y > 0)
		(*c2).x--;
	else
		(*c2).x++;
}

static void	get_transperency(t_icrd *crd1, t_icrd *crd2, int i, int cnt)
{
	if (i > cnt / 3)
	{
		crd1->color.c[0] += TRANSPARENCY2;
		crd2->color.c[0] += TRANSPARENCY2;
	}
	else if (i > cnt * 2 / 3)
	{
		crd1->color.c[0] += TRANSPARENCY3;
		crd2->color.c[0] += TRANSPARENCY3;
	}
}

void	anti_aliasing_x(t_icrd crd, t_icrd inc, int *cnt, t_img *img)
{
	int		i;
	t_icrd	crd1;
	t_icrd	crd2;

	i = 0;
	*cnt = (*cnt) / 3;
	anti_aliasing_x_init(crd, inc, &crd1, &crd2);
	while (i++ < *cnt)
	{
		get_transperency(&crd1, &crd2, i, *cnt);
		if (inc.x > 0)
		{
			crd1.x -= 1;
			print_pixel(crd1, img);
			crd2.x += 1;
			print_pixel(crd2, img);
		}
		else
		{
			crd1.x += 1;
			print_pixel(crd1, img);
			crd2.x -= 1;
			print_pixel(crd2, img);
		}
	}
}

void	anti_aliasing_y(t_icrd crd, t_icrd inc, int *cnt, t_img *img)
{
	int		i;
	t_icrd	crd1;
	t_icrd	crd2;

	i = 0;
	*cnt = (*cnt) / 3;
	anti_aliasing_y_init(crd, inc, &crd1, &crd2);
	while (i++ < *cnt)
	{
		get_transperency(&crd1, &crd2, i, *cnt);
		if (inc.y > 0)
		{
			crd1.y -= 1;
			print_pixel(crd1, img);
			crd2.y += 1;
			print_pixel(crd2, img);
		}
		else
		{
			crd1.y += 1;
			print_pixel(crd1, img);
			crd2.y -= 1;
			print_pixel(crd2, img);
		}
	}
}
