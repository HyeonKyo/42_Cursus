#include "fdf.h"

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
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
}

void	print_pixel_in_vector(t_img *img, t_map *data)
{
	int		i;
	t_2d_crd	*crd_2d;
	t_map_len	*map;

	crd_2d = multiplied_pixel(data);
	map = data->map;
	i = 0;
	while (i < data->size - 1)
	{
		if (i < map->x * (map->y - 1))
			bresenham(crd_2d[i], crd_2d[i + map->x], img);
		if (i % map->x != map->x - 1)
			bresenham(crd_2d[i], crd_2d[i + 1], img);
		i++;
	}
	free(crd_2d);
}
