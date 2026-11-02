/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:39:35 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 12:13:31 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_pixel_put(t_img *img, int x, int y, unsigned int color);

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

int	ft_draw_circle(t_display *display, int cx, int cy, int radius)
{
	int	x;
	int	y;

	y = cy - radius;
	while (y <= cy + radius)
	{
		x = cx - radius;
		while (x <= cx + radius)
		{
			if ((x - cx) * (x - cx)
				+ (y - cy) * (y - cy) <= radius * radius)
			{
				if (ft_pixel_put(&display->frame, x, y, YELLOW))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_draw_line(t_img *img, int x0, int y0, int x1, int y1,
		 unsigned int color)
{
	double	x;
	double	y;
	double	x_inc;
	double	y_inc;
	int	steps;
	int	i;

	steps = ft_max_int(ft_abs_int(x1 - x0), ft_abs_int(y1 - y0));
	if (steps == 0)
		return (0);
	x_inc = (double)(x1 - x0) / steps;
	y_inc = (double)(y1 - y0) / steps;
	x = x0;
	y = y0;
	i = 0;
	while (i <= steps)
	{
		ft_pixel_put(img, (int)x, (int)y, color);
		x += x_inc;
		y += y_inc;
		i++;
	}
	return (0);
}

int	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (1);
	*(unsigned int *)(img->addr + x * (img->bpp / 8) + y * img->sl) = color;
	return (0);
}
