/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:30:06 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 11:59:07 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	get_player_pos(t_data *data);
int	get_player_angle(t_data *data);
int	ft_is_player(char c);

int	ft_map_dim(t_map *map)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;

	max_i = 0;
	max_j = 0;
	i = 0;
	while (map->map_save[i])
	{
		j = 0;
		while (map->map_save[i][j])
		{
			if (j > max_j)
				max_j = j;
			j++;
		}
		if (i > max_i)
			max_i = i;
		i++;
	}
	max_i++;
	max_j++;
	map->dim[0] = max_i;
	map->dim[1] = max_j;
	return (0);
}

int	ft_player_init(t_data *data)
{
	if (get_player_pos(data))
		return (1);
	if (get_player_angle(data))
		return (1);
	data->player.move_speed = PLAYER_SPEED;
	data->player.rot_speed = PLAYER_ROT_SPEED;
	return (0);
}

int	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map_save[i])
	{
		j = 0;
		while (data->map.map_save[i][j])
		{
			if (ft_is_player(data->map.map_save[i][j]))
			{
				data->player.x = j;
				data->player.y = i;
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	get_player_angle(t_data *data)
{
	int	x;
	int	y;
	
	x = data->player.x;
	y = data->player.y;
	if (data->map.map_save[y][x] == 'E')
		return (data->player.angle = 0, 0);
	else if (data->map.map_save[y][x] == 'S')
		return (data->player.angle = M_PI / 2, 0);
	else if (data->map.map_save[y][x] == 'W')
		return (data->player.angle = M_PI, 0);
	else if (data->map.map_save[y][x] == 'N')
		return (data->player.angle = M_PI * 3 / 2, 0);
	return (1);
}

int	ft_is_player(char c)
{
	if (c == 'E')
		return (c);
	if (c == 'W')
		return (c);
	if (c == 'N')
		return (c);
	if (c == 'S')
		return (c);
	return (0);
}

