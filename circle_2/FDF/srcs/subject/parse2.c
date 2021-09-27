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

static int	return_color(double cur_z, int max_z)
{
	if (cur_z < (max_z / 3))
		return (COLOR1);
	else if (cur_z < (max_z * 2 / 3))
		return (COLOR2);
	else
		return (COLOR3);
}

static void	put_in_color(t_map *data)
{
	t_crd	*crd;
	int		max_z;
	int		i;

	crd = data->crd;
	max_z = data->map->z;
	i = -1;
	while (++i < data->size)
	{
		if (crd[i].color.n)
			continue ;
		crd[i].color.n = return_color(crd[i].z, max_z);
	}
}

t_map	*parsing_map(int ac, char **av)
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
	put_in_color(data);
	return (data);
}
