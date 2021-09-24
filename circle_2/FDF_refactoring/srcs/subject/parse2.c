#include "fdf.h"

static int	check_input(int ac, char **av)
{
	int	fd;

	if (ac < 1)
		error("Input error!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("Open error!");
	return (fd);
}

static void make_parallel_crd(t_map *data)
{
	t_2d_crd	*tmp;
	int			i;

	tmp = (t_2d_crd *)malloc(sizeof(t_2d_crd) * data->size);
	merror(tmp);
	i = -1;
	while (++i < data->size)
	{
		tmp[i].x = data->crd[i].x;
		tmp[i].y = data->crd[i].y;
		tmp[i].color.n = data->crd[i].color.n;
	}
	data->parallel_crd = tmp;
}

t_map *parsing_map(int ac, char **av)
{
	int		fd;
	char	*line;
	t_map	*data;

	line = 0;
	fd = check_input(ac, av);
	data = create_data();
	save_coordinate(fd, data);
	if (close(fd) < 0)
		error("Close error!");
	make_parallel_crd(data);//bonus전용
	return (data);
}
