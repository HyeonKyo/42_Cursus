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

void	expand_arr(int ***arr, t_map_len *map)
{
	//2차원 배열의 크기를 한 줄씩 확장해줌.
	int	i;
	int	**tmp;

	tmp = (int **)malloc(sizeof(int *) * (map->y + 1));
	merror(tmp);
	i = -1;
	while (++i < map->y)
		tmp[i] = (*arr)[i];
	if (*arr)
		free(*arr);
	*arr = tmp;
}

void	fill_value(int **arr, char **buf, t_map_len *map)
{
	static int	len_x;
	static int	max_z;
	int	i;

	if (len_x == 0)//지도의 x값 길이 넣어주기
	{
		while (buf[len_x])
			len_x++;
		map->x = len_x;
	}
	arr[map->y] = (int *)malloc(sizeof(int) * len_x);
	merror(arr[map->y]);
	i = -1;
	while (buf[++i])//split된 숫자들 arr[y]열에 하나씩 넣어주기
	{
		arr[map->y][i] = ft_atoi(buf[i]);
		if (arr[map->y][i] > max_z)
			max_z = arr[map->y][i];//높이 최댓값 = map_z
	}
	map->z = max_z;
}

int	**save_coordinate(int fd, t_map_len *map)
{
	//2차원 정수배열 arr에 맵의 x, y, z값 저장
	char	*line;
	char	**buf;
	int		**arr;

	arr = 0;
	while (get_next_line(fd, &line) > 0)
	{
		buf = ft_split(line, ' ');
		expand_arr(&arr, map);
		fill_value(arr, buf, map);
		clear_str(buf, &line);
		map->y++;
	}
	return (arr);
}
