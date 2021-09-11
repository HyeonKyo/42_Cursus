#include "fdf.h"

static int	mix_color(t_color color1, t_color color2, double per)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
	t_color			c;

	c.n = 0;
	red = (int)(color1.c[1] * (1 - per) + color2.c[1] * per);
	green = (int)(color1.c[2] * (1 - per) + color2.c[2] * per);
	blue = (int)(color1.c[3] * (1 - per) + color2.c[3] * per);
	c.c[1] = red;
	c.c[2] = green;
	c.c[3] = blue;
	if (per <= 0.3 || per >= 0.7)//원래의 선도 투명도 적용
		c.c[0] = TRANSPARENCY2;
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

void	anti_aliasing_x(t_icrd crd, t_icrd inc, int *cnt, t_img *img)
{
	int	i;
	t_icrd	crd1;
	t_icrd	crd2;

	i = 0;
	*cnt = (*cnt) * 4 / 9;
	crd1 = crd;
	crd2 = crd;
	crd1.color.c[0] += TRANSPARENCY1;
	crd2.color.c[0] += TRANSPARENCY1;
	if (inc.y > 0)
		crd2.y--;
	else
		crd2.y++;
	if (inc.x > 0)
	{
		while (i++ < *cnt)
		{
			if (i > (*cnt) / 3)
			{
				crd1.color.c[0] += TRANSPARENCY2;
				crd2.color.c[0] += TRANSPARENCY2;
			}
			else if (i > (*cnt) * 2 / 3)
			{
				crd1.color.c[0] += TRANSPARENCY3;
				crd2.color.c[0] += TRANSPARENCY3;
			}
			crd1.x -= 1;
			print_pixel(crd1, img);
			crd2.x += 1;
			print_pixel(crd2, img);
		}
	}
	else
	{
		while (i++ < *cnt)
		{
			if (i > (*cnt) / 3)
			{
				crd1.color.c[0] += TRANSPARENCY2;
				crd2.color.c[0] += TRANSPARENCY2;
			}
			else if (i > (*cnt) * 2 / 3)
			{
				crd1.color.c[0] += TRANSPARENCY3;
				crd2.color.c[0] += TRANSPARENCY3;
			}
			crd1.x += 1;
			print_pixel(crd1, img);
			crd2.x -= 1;
			print_pixel(crd2, img);
		}
	}
}

void	anti_aliasing_y(t_icrd crd, t_icrd inc, int *cnt, t_img *img)
{
	int	i;
	t_icrd	crd1;
	t_icrd	crd2;

	i = 0;
	*cnt = (*cnt) * 4 / 9;
	crd1 = crd;
	crd2 = crd;
	crd1.color.c[0] += TRANSPARENCY1;
	crd2.color.c[0] += TRANSPARENCY1;
	if (inc.x > 0)
		crd2.x--;
	else
		crd2.x++;
	if (inc.y > 0)
	{
		while (i++ < *cnt)
		{
			if (i > (*cnt) / 3)
			{
				crd1.color.c[0] += TRANSPARENCY2;
				crd2.color.c[0] += TRANSPARENCY2;
			}
			else if (i > (*cnt) * 2 / 3)
			{
				crd1.color.c[0] += TRANSPARENCY3;
				crd2.color.c[0] += TRANSPARENCY3;
			}
			crd1.y -= 1;
			print_pixel(crd1, img);
			crd2.y += 1;
			print_pixel(crd2, img);
		}
	}
	else
	{
		while (i++ < *cnt)
		{
			if (i > (*cnt) / 3)
			{
				crd1.color.c[0] += TRANSPARENCY2;
				crd2.color.c[0] += TRANSPARENCY2;
			}
			else if (i > (*cnt) * 2 / 3)
			{
				crd1.color.c[0] += TRANSPARENCY3;
				crd2.color.c[0] += TRANSPARENCY3;
			}
			crd1.y += 1;
			print_pixel(crd1, img);
			crd2.y -= 1;
			print_pixel(crd2, img);
		}
	}
}
