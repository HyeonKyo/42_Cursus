#include "fdf.h"

int		check_input(int ac, char **av)
{
	int	fd;

	if (ac < 1)
		error("Input error!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("Open error!");
	return (fd);
}

void	expand_data(t_map *data, int len_x)
{
	t_crd	*tmp;
	int		i;

	tmp = (t_crd *)malloc(sizeof(t_crd) * len_x);
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

void	get_crd_z(t_map *data, char *buf, int idx)
{
	int		i;
	char	**tmp;

	tmp = ft_split(buf, ',');
	data->crd[idx].z = ft_atoi(tmp[0]);
	if (tmp[1][0] != 0)
		data->crd[i].color = ft_atoi_hex(tmp[1]);
}

void	fill_value(char **buf, t_map *data)
{
	static int	len_x;
	static int	y;
	int			size;
	int			i;

	if (len_x == 0)//지도의 x값 길이 넣어주기
	{
		while (buf[len_x])
			len_x++;
		data->map->x = len_x;
	}
	expend_data(data, len_x);
	i = -1;
	size = data->size;
	while (buf[++i])//split된 숫자들 arr[y]열에 하나씩 넣어주기
	{
		data->crd[size + i].x = i;
		data->crd[size + i].y = y;
		get_crd_z(data, buf[i], i);
		if (data->crd[size + i].z > data->map->z)
			data->map->z = data->crd[size + i].z;//높이 최댓값 = map_z
	}
	y++;
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
