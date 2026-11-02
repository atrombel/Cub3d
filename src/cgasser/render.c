/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:38:16 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 12:13:31 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_draw_map(t_data *data);
void	draw_player(t_data *data);
void	draw_direction(t_data *data);

void	render_frame(t_data *data)
{
	ft_memset(data->display.frame.addr, 0,
		data->display.frame.sl * WIN_HEIGHT);

	ft_draw_map(data);
	draw_player(data);
	draw_direction(data);

	mlx_put_image_to_window(
		data->display.mlx_ptr,
		data->display.win_ptr,
		data->display.frame.ptr,
		0, 0);
}

int	ft_draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map_save[i])
	{
		j = 0;
		while (data->map.map_save[i][j])
		{
			if (data->map.map_save[i][j] == '1')
				if (ft_draw_wall(&data->display, i, j))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	draw_player(t_data *data)
{
	int	screen_x;
	int	screen_y;

	screen_x = (int)(data->player.x * data->display.scale);
	screen_y = (int)(data->player.y * data->display.scale);

	ft_draw_circle(&data->display, screen_x, screen_y,
		data->display.scale / 8);
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
		+ (int)(cos(data->player.angle) * DIRECTION_LENGTH);
	end_y = start_y
		+ (int)(sin(data->player.angle) * DIRECTION_LENGTH);
	ft_draw_line(&data->display.frame,
		      start_x, start_y, end_x, end_y, YELLOW);
	return ;
}
