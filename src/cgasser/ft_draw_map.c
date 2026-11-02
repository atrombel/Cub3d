/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:35:59 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 10:37:22 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_draw_wall(t_display *display, int i, int j);
int	ft_pixel_put(t_img *img, int x, int y, unsigned int color);
int	ft_draw_player(t_display *display, int i, int j);

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

int	ft_draw_wall(t_display *display, int i, int j)
{
	int	x;
	int	y;
	int	k;


	x = j * display->scale;
	y = i * display->scale;
	k = 0;
	while (k < display->scale)
	{
		if (ft_pixel_put(&display->frame, x + k, y, WHITE))
			return (1);
		if (ft_pixel_put(&display->frame, x + k,
			y + display->scale - 1, WHITE))
			return (1);
		if (ft_pixel_put(&display->frame, x, y + k, WHITE))
			return (1);
		if (ft_pixel_put(&display->frame,
			x + display->scale - 1,	y + k, WHITE))
			return (1);
		k++;
	}
	return (0);
}

