/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:39:35 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 10:37:22 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_abs_int(int n);
int	ft_max_int(int i, int j);

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
	x_inc = (double)(y1 - y0) / steps;
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

int	ft_abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max_int(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}
