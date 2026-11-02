/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:34:21 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 09:38:03 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	position_is_valid(t_data *data, double x, double y);

void	ft_try_move_player(t_data *data, double dx, double dy)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = data->player.x + dx;
	new_y = data->player.y + dy;

	check_x = new_x;
	if (dx > 0)
		check_x += PLAYER_RADIUS;
	if (dx < 0)
		check_x -= PLAYER_RADIUS;
	if (position_is_valid(data, check_x, data->player.y))
		data->player.x = new_x;
	check_y = new_y;
	if (dy > 0)
		check_y += PLAYER_RADIUS;
	if (dy < 0)
		check_y -= PLAYER_RADIUS;
	if (position_is_valid(data, data->player.x, check_y))
		data->player.y = new_y;
}

int	position_is_valid(t_data *data, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int)x;
	map_y = (int)y;

	if (map_x < 0 || map_y < 0
		|| map_y >= data->map.dim[0]
		|| map_x >= data->map.dim[1])
		return (0);
	if (data->map.map_save[map_y][map_x] == '1')
		return (0);
	return (1);
}
