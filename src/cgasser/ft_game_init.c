/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 16:00:20 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/05 16:56:19 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_win_init(t_display *display);
int	ft_img_init(t_display display);

int	ft_game_init(t_data *data)
{
	if (ft_win_init(&data->display) != 0)
		return (1);
	if (ft_img_init(data->display) != 0)
		return (1);
	return (0);

}

//init the window using the screen size
int	ft_win_init(t_display *display)
{
	display->mlx_ptr = mlx_init();
	if (!display->mlx_ptr)
		return (1);
	mlx_get_screen_size(display->mlx_ptr, &display->dim[0], &display->dim[1]);
	display->win_ptr = mlx_new_window(display->mlx_ptr, display->dim[1],
				   display->dim[2], "cub3doom");
	return (0);
}

int	ft_img_init(t_display display)
{
	(void)display;
	return (0);


}
