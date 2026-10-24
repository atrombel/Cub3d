/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_key_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 13:00:21 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/17 15:26:22 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_mlx_key_hook(int key, t_data *data)
{
	double	sin_a;
	double	cos_a;
	int	dx;
	int	dy;
	int	speed;
	int	key;

	dx = 0;
	dy = 0;
	sin_a = sin(player->angle);
	cos_a = cos(player->angle);
	speed = PLAYER_SPEED// * game.delta_time;
	speed_sin = speed * sin_a;
	speed_cos = speed * cos_a;
	if (key == K_ESC)
		return (ft_kill_mlx(data), 0);
	if (key == K_W)
	{
		dx += speed_cos;
		dx += speed_sin;
	}
	if (key == K_S)
	{
		dx += -speed_cos;
		dx += -speed_sin;
	}
	if (key == K_D)
	{
		dx += -speed_cos;
		dx += speed_sin;
	}
	if (key == K_A)
	{
		dx += speed_cos;
		dx += -speed_sin;
	}
	player->pos[0] += dx;
	player->pos[1] += dy;
	if (key == K_LEFT)
		player->angle -= PLAYER_ROT_SPEED //* self_game_delta_time
	if (key == K_RIGHT)
		player->angle += PLAYER_ROT_SPEED //* self_game_delta_time
	player->angle %= 2 * M_PI;




	
}
