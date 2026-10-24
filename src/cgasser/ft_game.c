/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 14:43:41 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/17 15:26:21 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"
#include <time.h>

int	ft_game(t_data *data)
{
	ft_game_init(data);
	printf("game initalized\n");
//	mlx_key_hook(data->display.win_ptr, &ft_key_hook, data);

//	mlx_loop_hook(data->display.win_ptr, &ft_loop_hook, data);
	
//	mlx_hook(data->display.win_ptr, 17, 0L, &ft_kill_mlx, &data->display);

//	mlx_loop(data->display.mlx_ptr);
	
	sleep(5);
	ft_kill_mlx(&data->display);
	return (0);
	

}
