/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:38:16 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 10:37:23 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

void	clear_Frame(t_data *data);
void	draw_player(t_data *data);
void	draw_direction(t_data *data);

void	render_frame(t_data *data)
{
	clear_frame(data);

	draw_map(data);
	draw_player(data);
	draw_direction(data);

	mlx_put_image_to_window(
		data->display.mlx_ptr,
		data->display.win_ptr,
		data->display.frame.ptr,
		0, 0);
}

void	clear_Frame(t_data *data)
{
	ft_memeset(data->display.frame.addr, 0,
		data->display.frame.sl * WIN_HEIGHT);
}

void	draw_player(t_data *data)
{
	int	screen_x;
	int	screen_y;

	screen_x = (int)(data->player.x * data->display.scale);
	screen_y = (int)(data->player.y * data->display.scale);

	ft_draw_circle(&data->display, screen_x, screen_y,
		data->display.scale / 4);
}

void	draw_direction(t_data *data)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	start_x = (int)(data->player.x * data->display.scale);
	start_y = (int)(data->player.y * data->display.scale);

	end_x = start_x
		+ cos(data->player.angle) * DRECTION_LENGTH;
	end_y = start_y
		+ cos(data->player.angle) * DRECTION_LENGTH;
	return (ft_draw_line(&data->display.frame,
		      start-x, start_y, end_x, end_y, YELLOW))
}
