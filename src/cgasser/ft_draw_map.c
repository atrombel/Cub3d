/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:35:59 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/23 15:18:07 by cgasser          ###   ####lausanne.ch   */
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
		printf("image being drew...\n");
		j = 0;
		while (data->map.map_save[i][j])
		{
			if (data->map.map_save[i][j] == '1')
				if (ft_draw_wall(&data->display, i, j))
					return (1);
			if (ft_is_player(data->map.map_save[i][j]))
				if (ft_draw_player(&data->display, i, j))
					return (1);
			j++;
		}
		i++;
	}
	printf("image drew\n");
	mlx_put_image_to_window(data->display.mlx_ptr,
			 data->display.win_ptr,
			 data->display.frame.ptr, 0, 0);
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

//draw the color rgb[] ath the coordinated x, y on the mlx image
int	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (1);
	*(unsigned int *)(img->addr + x * (img->bpp / 8) + y * img->sl) = color;
	return (0);
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
