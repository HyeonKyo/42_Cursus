#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7

# define GR 0x0000FF00
# define RED 0x00FF0000

# define COLOR1 0x00FF33FF
# define COLOR2 0x00CC99FF
# define COLOR3 0x00CC99FF

# define MLX_X_SIZE 1600
# define MLX_Y_SIZE 900
# define IMG_X_SIZE 1300
# define IMG_Y_SIZE 700

typedef	union	s_color
{
	unsigned char	c[4];
	int				n;
}				t_color;

typedef struct	s_crd
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}				t_crd;//coordinate

typedef struct s_2d_crd
{
	double	x;
	double	y;
	t_color	color;
}				t_2d_crd;

typedef struct s_map_len
{
	int	x;
	int	y;
	int	z;
}				t_map_len;

typedef struct	s_map
{
	int			size;
	t_map_len	*map;
	t_crd		*crd;
	t_2d_crd	*crd_2d;
}				t_map;

typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} 				t_img;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	*data;
}				t_ptr;


typedef struct	s_icrd
{
	int		x;
	int		y;
	t_color	color;
}				t_icrd;

typedef struct	s_unit
{
	t_crd	u;
	t_crd	v;
	t_crd	n;
}				t_unit;//unit vector


int		get_next_line(int fd, char **line);
//ft_utils
void	error(const char *str);
void	merror(void *ptr);
int		find_max(int a, int b, int c);

//parse
void	save_coordinate(int fd, t_map *data);
t_map *parsing_map(int ac, char **av);
//parse_utils
void	clear_arr(int **arr, t_map_len *map);
void	clear_str(char **buf, char **line);
t_map	*create_data(void);
//vector
void	rotate_x_axis(t_map *data, double rad);
void	rotate_z_axis(t_map *data, double rad);
void	rotate_y_axis(t_map *data, double rad);

void	scail_vector(t_crd *crd, t_crd scail);
double	distance_crd(t_crd c1, t_crd c2);
double	size_crd(t_crd crd);
void	rotate_unit_vector(t_unit new, t_crd *data_crd);
t_crd	cross_vector(t_crd v1, t_crd v2);
void	translation_vector(t_crd *crd, t_crd trans);

//iso_vector
void	isometric_view(t_map *data);
//bresenham
void	get_color(t_2d_crd start, t_2d_crd end, t_icrd *crd, int flag);
void	get_crd_x(t_icrd *crd, t_icrd inc, t_icrd diff, int *f);
void	get_crd_y(t_icrd *crd, t_icrd inc, t_icrd diff, int *f);
void	based_x(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img);
void	based_y(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img);
void	bresenham(t_2d_crd start, t_2d_crd end, t_img *img);

//pixel
void	print_pixel(t_icrd crd, t_img *img);

//print_img
void	multiplied_pixel(t_map *data);
void	print_pixel_in_vector(t_img *img, t_map *data);
void	print_map(t_ptr *ptr);
void	make_graphic(t_map *data);
//event_move
void	reprint_map(t_ptr *ptr);
void	right(t_map *data);
void	left(t_map *data);
void	up(t_map *data);
void	down(t_map *data);
//event_zoom
void	zoom(t_map *data);
void	unzoom(t_map *data);
//make_ptr
void	make_ptr(t_ptr *ptr, t_map *data);

int		ft_atoi_hex(char *str);

void	print_data(t_map *data);
void	print_2d_data(t_map *data);
#endif