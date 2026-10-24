/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_dim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:54:04 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/23 11:58:29 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_map_dim(t_map *map)
{
	int	i;
	int	j;
	int	max_i;
	int	max_j;

	max_i = 0;
	max_j = 0;
	i = 0;
	while (map->map_save[i])
	{
		j = 0;
		while (map->map_save[i][j])
		{
			if (j > max_j)
				max_j = j;
			j++;
		}
		if (i > max_i)
			max_i = i;
		i++;
	}
	max_i++;
	max_j++;
	map->dim[0] = max_i;
	map->dim[1] = max_j;
	return (0);
}
