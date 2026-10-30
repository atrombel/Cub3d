/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:57:58 by atrombel          #+#    #+#             */
/*   Updated: 2026/09/18 13:58:00 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "atrombel.h"

void	debug_print_data(t_data *data)
{
	int	i;

	printf("===============================================\n");
	printf("data address     : %p\n", (void *)data);
	printf("no_path address  : %p\n", (void *)data->id.no_path);
	printf("so_path address  : %p\n", (void *)data->id.so_path);
	printf("we_path address  : %p\n", (void *)data->id.we_path);
	printf("ea_path address  : %p\n", (void *)data->id.ea_path);

	printf("\n--- MAP ---\n");
	printf("map_save address : %p\n", (void *)data->map.map_save);
	printf("line              : %d\n", data->map.line);
	printf("map_started       : %d\n", data->map.map_started);
	printf("map_ended         : %d\n", data->map.map_ended);
	printf("ismap_stored      : %d\n", data->map.ismap_stored);
	i = 0;
	printf("color F =         : ");
	while (i != 2)
	{
		printf("%d,", data->id.f[i]);
		i++;
	}

	printf("%d", data->id.f[i]);

	i = 0;
	printf("\n");

	printf("color C =         : ");
	while (i != 2)
	{
		printf("%d,", data->id.c[i]);
		i++;
	}
		printf("%d", data->id.c[i]);

	printf("\n");
	if (!data->map.map_save)
	{
		printf("map_save is NULL\n");
		return ;
	}
	i = 0;
	while (data->map.map_save[i])
	{
		printf("map_save[%d] = %s\n", i, data->map.map_save[i]);
		i++;
	}
	printf("map_save[%d] = NULL\n", i);
	printf("player_x = %d\n", data->map.player_x);
	printf("player_y = %d\n",data->map.player_y);
		data->map.map_y_max = i;
	printf("data->map.map_y_max =  %d\n",data->map.map_y_max);
	printf("data->map.map_x_max =  %d\n",data->map.map_x_max);


}

int	main(int argc, char **argv)
{
	t_data data;

	ft_init(&data);
	if (parser_main(&data, argv[1], argc) == 1)
		return (free_all(&data), 1);
	debug_print_data(&data);
	printf("=======================================================================================\n");// to remove
	printf("end of execution, MAP VALID\n");// to remove
	free_all(&data);
	return (0);
}
