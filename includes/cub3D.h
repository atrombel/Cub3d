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
# include <fcntl.h>

typedef struct s_identifier
{
	char	*no_path;
	int		no_check_status;
	char	*so_path;
	int		so_check_status;
	char	*we_path;
	int		we_check_status;
	char	*ea_path;
	int		ea_check_status;
	int		f[3];
	int		f_check_status;
	int		c[3];
	int		c_check_status;
} t_identifier;

typedef struct s_map
{
	int		map_fd;
}	t_map;

typedef struct s_data
{
	t_identifier	identifier;
	t_map			map;
}	t_data;


#endif