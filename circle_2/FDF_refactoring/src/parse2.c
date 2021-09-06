#include "fdf.h"

t_crd	*make_coordinate(int **arr, t_map_len *map)
{
	//2차 배열 arr에 저장한 값을 구조체 t_crd에 저장
	t_crd	*crd;
	t_2d_crd	idx;
	int	len;
	int	crd_idx;

	len = map->x * map->y;
	crd = (t_crd *)malloc(sizeof(t_crd) * len);
	merror(crd);
	idx.y = -1;
	crd_idx = 0;
	while (++idx.y < map->y)
	{
		idx.x = -1;
		while (++idx.x < map->x)
		{
			crd[crd_idx].x = idx.x;
			crd[crd_idx].y = idx.y;
			crd[crd_idx++].z = arr[idx.y][idx.x];
		}
	}
	clear_arr(arr, map);
	return (crd);
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
	//save vector
	//gnl로 한 줄씩 읽음
	//그 문자열 한줄을 split으로 잘라냄
	//그 문자열의 개수가 map_x길이가 됨
	//그 map_x만큼 int buf할당
	//int **arr[i]에 그 buf넣기
	//int **arr의 할당은 계속 1씩 늘려준다.
	//하지만 arr[i]의 주소값은 계속 남아있으므로 문제 없다.
	//정수 배열을 다 저장했으면, 그 정수 배열의 인덱스들이 x, y값이 되고 값이 z가 된다.
	//max_x * max_y만큼 벡터 구조체 배열 할당 후 차례로 넣어준다.
	//그 구조체 리턴
}
