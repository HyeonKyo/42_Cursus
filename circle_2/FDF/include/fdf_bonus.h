/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonkki <hyeonkki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:51:53 by hyeonkki          #+#    #+#             */
/*   Updated: 2021/09/28 14:51:54 by hyeonkki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_P 35
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4

void	save_parallel_data(t_map *data);

void	rotate_x_axis(t_map *data, double rad);
void	rotate_z_axis(t_map *data, double rad);
void	rotate_y_axis(t_map *data, double rad);
void	translation_vector(t_crd *crd, t_crd trans);

void	right(t_map *data);
void	left(t_map *data);
void	up(t_map *data);
void	down(t_map *data);

void	zoom_in(t_map *data);
void	zoom_out(t_map *data);

void	rotate_x(t_map *data, double rad);
void	rotate_y(t_map *data, double rad);
void	rotate_z(t_map *data, double rad);
void	parallel_rotate(t_ptr *ptr, double rad);

void	reprint_map(t_ptr *ptr);
void	move_map(int keycode, t_ptr *ptr);
void	zoom_map(int keycode, t_ptr *ptr);
void	parallel_view(t_ptr *ptr, int *flag);
void	rotate_map(int keycode, t_ptr *ptr, int flag);

#endif
