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

//parser_map_file_type_check check if map file is .cub or not
//parser_map_open_check use fonction "open" to check wether the file is valid,if valid it stores it in the int map_fd;
//parser_map_check "NO SO WE EA and color F and C" if ok in the file
// and it stores the map in data->map.map_save which is a char	**map_save;
int	parser_main(t_data *data, char *path_to_map)
{
	if (parser_map_file_type_check(path_to_map))
		return (1);
	if (parser_map_open_check(path_to_map, data))
		return (1);
	if (parser_map_check(data))
		return (1);
	//etc
	return (0);
}