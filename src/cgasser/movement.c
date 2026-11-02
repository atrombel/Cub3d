/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:33:30 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 09:38:04 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

void	normalize_angle(double *angle);

void	ft_update_rotation(t_data *data)
{
	if (data->keys.left)
		data->player.angle -= data->player.rot_speed
			* data->delta_time;
	if (data->keys.right)
		data->player.angle += data->player.rot_speed
			* data->delta_time;
	normalize_angle(&data->player.angle);
}

void	normalize_angle(double *angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
}

void	ft_update_movement(t_data *data)
{
	double	move_x;
	double	move_y;
	double	speed;

	move_x = 0;
	move_y = 0;
	speed = data->player.move_speed * data->delta_time;
	if (data->keys.w)
	{
		move_x += cos(data->player.angle) * speed;
		move_y += sin(data->player.angle) * speed;
	}
	if (data->keys.s)
	{
		move_x -= cos(data->player.angle) * speed;
		move_y -= sin(data->player.angle) * speed;
	}
	if (data->keys.a)
	{
		move_x += cos(data->player.angle) * speed;
		move_y -= sin(data->player.angle) * speed;
	}
	if (data->keys.d)
	{
		move_x -= cos(data->player.angle) * speed;
		move_y += sin(data->player.angle) * speed;
	}
	ft_try_move_player(data, move_x, move_y);
}
