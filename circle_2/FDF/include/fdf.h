/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:51:42 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:51:45 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** =============================================================================
** Dependencies
** =============================================================================
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

/*
** =============================================================================
** Macro Declaration
** =============================================================================
*/

# define TRUE 1
# define FALSE 0

# define ESC 53

# define COLOR1 0x0033FF33
# define COLOR2 0x006633CC
# define COLOR3 0x00FF99FF

# define TRANSPARENCY1 0xCC
# define TRANSPARENCY2 0x80
# define TRANSPARENCY3 0x33

# define MLX_X_SIZE 1600
# define MLX_Y_SIZE 900
# define IMG_X_SIZE 1600
# define IMG_Y_SIZE 900

/*
** =============================================================================
** Type Definition
** =============================================================================
*/

typedef unsigned char	t_uchar;

/*
** =============================================================================
** Union type Definition
** =============================================================================
*/

typedef union u_color
{
	t_uchar	c[4];
	int		n;
}			t_color;

/*
** =============================================================================
** Struct type Definition
** =============================================================================
*/

typedef struct s_crd
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}			t_crd;

typedef struct s_2d_crd
{
	double	x;
	double	y;
	t_color	color;
}			t_2d_crd;

typedef struct s_map_len
{
	int	x;
	int	y;
	int	z;
}			t_map_len;

typedef struct s_map
{
	int			size;
	t_map_len	*map;
	t_2d_crd	min;
	t_crd		*crd;
	t_2d_crd	*crd_2d;
	t_2d_crd	*parallel_crd;
}			t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	*data;
}			t_ptr;

typedef struct s_icrd
{
	int		x;
	int		y;
	t_color	color;
}			t_icrd;

/*
** =============================================================================
** Hk_function Sources
** =============================================================================
*/

int			get_next_line(int fd, char **line);
int			ft_atoi_hex(char *str);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
void		*ft_memset(void *ptr, int value, size_t num);
char		**ft_split(char const *s, char c);
char		*ft_strchr(char *str, int c);
size_t		ft_strlen(const char *str);

/*
** =============================================================================
** Utility Sources
** =============================================================================
*/

void		error(const char *str);
void		merror(void *ptr);
int			find_max(int a, int b, int c);

void		clear_arr(int **arr, t_map_len *map);
void		clear_str(char **buf, char **line);
t_map		*create_data(void);

/*
** =============================================================================
** Subject Sources
** =============================================================================
*/

void		save_coordinate(int fd, t_map *data);
t_map		*parsing_map(int ac, char **av);

void		isometric_view(t_map *data);

void		get_color(t_2d_crd start, t_2d_crd end, t_icrd *crd, int flag);
int			get_crd_x(t_icrd *crd, t_icrd inc, t_icrd diff, int *f);
int			get_crd_y(t_icrd *crd, t_icrd inc, t_icrd diff, int *f);
void		based_x(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img);
void		based_y(t_2d_crd start, t_2d_crd end, t_icrd diff, t_img *img);
void		bresenham(t_2d_crd start, t_2d_crd end, t_img *img);
void		anti_aliasing_x(t_icrd crd, t_icrd inc, int *cnt, t_img *img);
void		anti_aliasing_y(t_icrd crd, t_icrd inc, int *cnt, t_img *img);

void		print_pixel(t_icrd crd, t_img *img);

t_2d_crd	*multiplied_pixel(t_map *data);
void		print_pixel_in_vector(t_img *img, t_map *data);
void		print_map(t_ptr *ptr);
void		make_graphic(t_map *data);

void		make_ptr(t_ptr *ptr, t_map *data);

#endif
