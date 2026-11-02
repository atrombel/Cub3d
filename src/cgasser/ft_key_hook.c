/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 11:33:56 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/25 17:26:12 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_key_hook(int key, t_data *data)
{
	int	key;

	if (key == K_W || key == K_A || key == K_S
		key == K_D)
		if (ft_player_mov(key))
			return (1);
	if (key == K_LEFT || key == K_RIGHT)
		if (ft_player_rot(key))
			return (1);
	if (key == K_ESC)
		return (ft_kill_mlx(data), 0);
}

int	ft_player_mov(, int key)
{
	double	dx;
	double	dy;

	dx = 0;
	dy = 0;
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
}

double	ft_delta_x(t_player *player)
{
	double	sin_a;
	double	cos_a;
	int	speed;

	sin_a = sin(player->angle);
	cos_a = cos(player->angle);
	speed = PLAYER_SPEED// * game.delta_time;
	speed_sin = speed * sin_a;
	speed_cos = speed * cos_a;

}

int	ft_player_rot(, int key)
{
	if (key == K_LEFT)
		player->angle -= PLAYER_ROT_SPEED //* self_game_delta_time
	if (key == K_RIGHT)
		player->angle += PLAYER_ROT_SPEED //* self_game_delta_time
	player->angle %= 2 * M_PI;

}
