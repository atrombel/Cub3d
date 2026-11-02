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

void	ft_try_move_player(t_data *data, double dx, double dy)
{
	double	new_x;
	double	new_x;

	new_x = data->player.x + dx;
	new_y = data->player.y + dy;

	if (position_is_valid(data, new_x, data->palyer.y))
		data->player.x = new_x;
	if (position_is_valid(data, data->player.x, new_y))
		data->player.y = new_y;
}

int	position_is_valid(t_data *data, double x, double y)
{
	int map_x;
	int map_y;

	map_x = (int)x;
	map_y = (int)y;

	if (data->map.map_save[map_y][map_x] == '1')
		return (0);
	return (1);
}
