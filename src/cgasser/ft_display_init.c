/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:20:14 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/23 10:29:04 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_win_init(t_display *display);
int	ft_get_scale(t_data *data);
int	ft_img_init(t_display *display);

int	ft_display_init(t_data *data)
{
	if (ft_win_init(&data->display))
		return (1);
	printf("window initalized\n");
	ft_map_dim(&data->map);
	printf("map dimensions initalized\n");
	if (ft_get_scale(data))
		return (1);
	printf("scale initalized\n");
	if (ft_img_init(&data->display))
		return (1);
	printf("image initalized\n");
	printf("map: %d x %d, scale: %d\n",
		data->map.dim[1], data->map.dim[0], data->display.scale);
	return (0);

}

//init the window using the screen size
int	ft_win_init(t_display *display)
{
	display->mlx_ptr = mlx_init();
	if (!display->mlx_ptr)
		return (1);
	display->win_ptr = mlx_new_window(display->mlx_ptr, WIN_WIDTH,
				   WIN_HEIGHT, "cub3doom");
	if (!display->win_ptr)
		return (1);
	return (0);
}

//calculate the smallest scale factor between the map and the size of the screen
//so the map fits entirely inside the screen
int	ft_get_scale(t_data *data)
{
	int	scale_x;
	int	scale_y;

	scale_x = WIN_HEIGHT / data->map.dim[0];
	scale_y = WIN_WIDTH / data->map.dim[1];
	printf("scale x: %d\n", scale_x);
	printf("scale y: %d\n", scale_y);
	if (scale_x < 1 || scale_y < 1)
		return (1);
	if (scale_x < scale_y)
		data->display.scale = scale_x;
	else
		data->display.scale = scale_y;
	return (0);
}

//init the img object (frame)
int	ft_img_init(t_display *display)
{
	display->frame.ptr = mlx_new_image(display->mlx_ptr, WIN_WIDTH, 
				    WIN_HEIGHT);
	if (!display->frame.ptr)
		return (1);
	display->frame.addr = mlx_get_data_addr(display->frame.ptr, 
					 &display->frame.bpp,
					 &display->frame.sl,
					 &display->frame.en);
	return (0);
}

