#include "fdf.h"

void	make_ptr(t_ptr *ptr, t_map *data)
{
	ft_memset(ptr, 0, sizeof(t_ptr));
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, MLX_X_SIZE, MLX_Y_SIZE, "FDF");
	ptr->data = data;
}
