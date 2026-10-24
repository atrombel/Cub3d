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
int	ft_kill_mlx(t_display *display);
int	ft_draw_map(t_data *data);
int	ft_map_dim(t_map *map);
int	ft_is_player(char c);;

#endif
