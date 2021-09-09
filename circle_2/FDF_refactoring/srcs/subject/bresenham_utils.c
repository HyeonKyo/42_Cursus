#include "fdf.h"

static int	mix_color(t_color color1, t_color color2, double per)
{
	int	red;
	int	green;
	int	blue;
	int	c;

	red = (int)(color1.c[1] * (1 - per) + color2.c[1] * per);
	green = (int)(color1.c[2] * (1 - per) + color2.c[2] * per);
	blue = (int)(color1.c[3] * (1 - per) + color2.c[3] * per);
	c = (red << 16) + (green << 8) + blue;
	return (c);
}

void	get_color(t_2d_crd start, t_2d_crd end, t_icrd *crd, int flag)
{
	t_color	color1;
	t_color	color2;
	double	per;

	if (start.color.n == end.color.n)
		crd->color.n = start.color.n;
	else
	{
		if (flag == TRUE)//x
			per = (crd->x - start.x) / (end.x - start.x);
		else//y
			per = (crd->y - start.y) / (end.y - start.y);
		color1.n = start.color.n;
		color2.n = end.color.n;
		crd->color.n = mix_color(color1, color2, per);
	}
}

void	get_crd_x(t_icrd *crd, t_icrd inc, t_icrd diff, int *f)
{
	crd->x += inc.x;
	if (*f >= 0)
	{
		crd->y += inc.y;
		*f += 2 * (diff.y - diff.x);
	}
	else
		*f += 2 * diff.y;
}

void	get_crd_y(t_icrd *crd, t_icrd inc, t_icrd diff, int *f)
{
	crd->y += inc.y;
	if (*f >= 0)
	{
		crd->x += inc.x;
		*f += 2 * (diff.x - diff.y);
	}
	else
		*f += 2 * diff.x;
}

