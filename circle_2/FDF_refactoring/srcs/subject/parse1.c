#include "fdf.h"

static void	expand_data(t_map *data, int len_x)
{
	t_crd	*tmp;
	int		i;

	tmp = (t_crd *)malloc(sizeof(t_crd) * (data->size + len_x));
	merror(tmp);
	i = -1;
	while (++i < data->size)
	{
		tmp[i].x = data->crd[i].x;
		tmp[i].y = data->crd[i].y;
		tmp[i].z = data->crd[i].z;
	}
	if (data->crd)
		free(data->crd);
	data->crd = tmp;
}

static void	get_crd_z(t_map *data, char *buf, int idx)
{
	int		size;
	char	**tmp;

	size = data->size;
	tmp = ft_split(buf, ',');
	data->crd[size + idx].z = ft_atoi(tmp[0]);
	if (tmp[1] && tmp[1][0] != 0)
		data->crd[size + idx].color.n = ft_atoi_hex(tmp[1]);
}

static void	fill_value(char **buf, t_map *data)
{
	static int	len_x;
	static int	save_y;
	int			size;
	int			i;

	if (len_x == 0)//지도의 x값 길이 넣어주기
	{
		while (buf[len_x])
			len_x++;
		data->map->x = len_x;
	}
	expand_data(data, len_x);
	i = -1;
	size = data->size;
	while (buf[++i])
	{
		data->crd[size + i].x = i;
		data->crd[size + i].y = save_y;
		get_crd_z(data, buf[i], i);
		if (data->crd[size + i].z > data->map->z)
			data->map->z = data->crd[size + i].z;
	}
	save_y++;
	data->size += len_x;
}

void	save_coordinate(int fd, t_map *data)
{
	char	*line;
	char	**buf;

	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_split(line, ' ');
		fill_value(buf, data);
		clear_str(buf, &line);
		data->map->y++;
	}
}
