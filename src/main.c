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

int	main(int argc, char **argv)
{
	t_data data;
	if (arguments_nbr_check(argc) == 1)
		return (1);
	ft_bzero(&data, sizeof(t_data));
	if (parser_main(&data, argv[1]) == 1)
		return (1);
	printf("yeahbruh\n");
	return (0);
}
