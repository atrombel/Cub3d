/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:54:50 by atrombel          #+#    #+#             */
/*   Updated: 2026/09/18 13:55:08 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_map
{
	int	map_fd;
}	t_map;

typedef struct s_data
{
	t_map map;
}	t_data;


#endif