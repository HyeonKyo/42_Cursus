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

t_map *parsing_map(int ac, char **av)
{
	int		fd;
	char	*line;
	t_map	*data;

	line = 0;
	fd = check_input(ac, av);
	data = create_data();
	save_coordinate(fd, data);
	return (data);
}
