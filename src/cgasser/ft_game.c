/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:43:41 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/30 10:47:39 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include <time.h>

int	ft_game(t_data *data)
{
	if (ft_game_init(data))
		return (1);
	mlx_hook(data->display.win_ptr, 17, 0L, &ft_kill_mlx, &data->display);
	mlx_hook(data->display.win_ptr, 2, 1L << 0, &ft_key_press, data);
	mlx_hook(data->display.win_ptr, 3, 1L << 1, &ft_key_release, data);
	mlx_loop_hook(data->display.mlx_ptr, &ft_loop_hook, data);
	mlx_loop(data->display.mlx_ptr);
	return (0);
}
