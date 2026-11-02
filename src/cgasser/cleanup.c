/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 10:37:35 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 10:38:14 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_kill_mlx(t_data *data)
{
	mlx_destroy_window(data->display.mlx_ptr, data->display.win_ptr);
	mlx_destroy_display(data->display.mlx_ptr);
	return (0);
}
