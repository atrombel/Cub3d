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
	printf("data address    : %p\n", (void *)data);
	printf("no_path address : %p\n", (void *)data->id.no_path);
	printf("so_path address : %p\n", (void *)data->id.so_path);
	printf("we_path address : %p\n", (void *)data->id.we_path);
	printf("ea_path address : %p\n", data->id.ea_path);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (arguments_nbr_check(argc) == 1)
		return (1);
	ft_init(&data);
	if (parser_main(&data, argv[1]) == 1)
		return (1);

	printf("yeahbruh\n");// to remove
	debug_print_data(&data);

	return (0);
}
