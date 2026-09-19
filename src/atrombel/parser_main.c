/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 13:47:29 by atrombel          #+#    #+#             */
/*   Updated: 2026/09/19 13:47:30 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "atrombel.h"

int	parser_main(t_data *data, char *path_to_map)
{
	if (parser_map_file_type_check(path_to_map))
		return (1);
	(void)data;
	// if (parser_map_open_check(data))
	// 	return (1);
	// if (parser_map_identifiers_check(data))
	// 	return (1);
	// if (parser_map_elements_check(data))
	// 	return (1);
	// if (parser_map_size_check(data))
	// 	return (1);
	// if (parser_map_validity_check(data))
	// 	return (1);
	return (0);
}