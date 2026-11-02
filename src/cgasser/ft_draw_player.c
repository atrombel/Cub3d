/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 06:56:10 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 09:41:19 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_draw_player(t_data *data)
{

	ft_draw_player(&data->display, data->player.pos[0],
		data->player.pos[1]);


}

int	ft_draw_player(t_display *display, int i, int j)
{
	int	cx;
	int	cy;
	int	x;
	int	y;
	int	radius;

	cx = j * display->scale + display->scale / 2;
	cy = i * display->scale + display->scale / 2;
	radius = display->scale / 2;
	y = cy - radius;
	while (y <= cy + radius)
	{
		x = cx - radius;
		while (x <= cx + radius)
		{
			if ((x - cx) * (x - cx)
				+ (y - cy) * (y - cy) <= radius * radius)
				if (ft_pixel_put(&display->frame, x, y, YELLOW))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
