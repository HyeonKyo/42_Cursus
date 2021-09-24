#include "fdf.h"

static int	mix_color(t_color color1, t_color color2, double per)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	t_color			c;

	c.n = 0;
	red = (unsigned char)((double)color1.c[1] * (1 - per) + (double)color2.c[1] * per);
	green = (unsigned char)((double)color1.c[2] * (1 - per) + (double)color2.c[2] * per);
	blue = (unsigned char)((double)color1.c[3] * (1 - per) + (double)color2.c[3] * per);
	c.c[1] = red;
	c.c[2] = green;
	c.c[3] = blue;
	c.c[0] = TRANSPARENCY1;
	return (c.n);
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

int	get_crd_x(t_icrd *crd, t_icrd inc, t_icrd diff, int *f)
{
	crd->x += inc.x;
	if (diff.y == 0)
		return (0);
	if (*f >= 0)
	{
		crd->y += inc.y;
		*f += 2 * (diff.y - diff.x);
		return (1);
	}
	else
		*f += 2 * diff.y;
	return (0);
}

int	get_crd_y(t_icrd *crd, t_icrd inc, t_icrd diff, int *f)
{
	crd->y += inc.y;
	if (diff.x == 0)
		return (0);
	if (*f >= 0)
	{
		crd->x += inc.x;
		*f += 2 * (diff.x - diff.y);
		return (1);
	}
	else
		*f += 2 * diff.x;
	return (0);
}
