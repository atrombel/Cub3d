/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:22:34 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/30 10:22:47 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

//draw the color rgb[] ath the coordinated x, y on the mlx image
int	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return (1);
	*(unsigned int *)(img->addr + x * (img->bpp / 8) + y * img->sl) = color;
	return (0);
}
