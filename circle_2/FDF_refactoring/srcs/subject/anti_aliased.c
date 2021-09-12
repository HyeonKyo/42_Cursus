#include "fdf.h"

void	anti_aliasing_x(t_icrd crd, t_icrd inc, int *cnt, t_img *img)
{
	int	i;
	t_icrd	crd1;
	t_icrd	crd2;

	i = 0;
	*cnt = (*cnt) * 4 / 9;//기준 명확히 하기
	crd1 = crd;
	crd2 = crd;
	crd1.color.c[0] += TRANSPARENCY1;
	crd2.color.c[0] += TRANSPARENCY1;
	if (inc.y > 0)//아랫 줄 anti aliasing의 y좌표 값 설정
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
