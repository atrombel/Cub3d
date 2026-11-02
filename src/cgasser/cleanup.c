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

int	ft_kill_mlx(t_display *display)
{
	printf("mlx cleaning...\n");
	mlx_destroy_window(display->mlx_ptr, display->win_ptr);
	mlx_destroy_display(display->mlx_ptr);
	printf("mlx cleaned\n");
	return (0);
}
