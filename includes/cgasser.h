/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgasser.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 15:30:45 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/23 15:16:38 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGASSER_H
# define CGASSER_H

# include "cub3D.h"

int	ft_game(t_data *data);
int	ft_game_init(t_data *data);
int	ft_display_init(t_data *data);
int	ft_player_init(t_data *data);

double	get_time(void);

int	ft_map_dim(t_map *map);
int	ft_draw_map(t_data *data);

int	ft_key_press(int key, t_data *data);
int	ft_key_release(int key, t_data *data);
int	ft_loop_hook(t_data *data);

void	ft_update_rotation(t_data *data);
void	ft_update_movement(t_data *data);

void	render_frame(t_data *data);
int	ft_draw_circle(t_display *display, int cx, int cy, int radius);
int	ft_draw_wall(t_display *display, int i, int j);
int	ft_draw_line(t_img *img, int x0, int y0, int x1, int y1,
		 unsigned int color);

int	ft_abs_int(int n);
int	ft_max_int(int i, int j);

void	ft_try_move_player(t_data *data, double dx, double dy);

int	ft_kill_mlx(t_data *data);
#endif
