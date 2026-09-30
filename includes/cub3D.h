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
# include <stdbool.h>

//attention to free les char * liked to " au no ea we so "
// est ce que je dois stocker les fd des path ?
typedef struct s_identifier
{
	char	*no_path;
	bool	no_check_status;
	char	*so_path;
	bool	so_check_status;
	char	*we_path;
	bool	we_check_status;
	char	*ea_path;
	bool	ea_check_status;
	int		f[3];
	int		f_check_status;
	int		c[3];
	int		c_check_status;
} t_identifier;

typedef struct s_map
{
	bool	map_started;
	int		map_fd;// TO CLOSE
}	t_map;

typedef struct s_data
{
	t_identifier	id;
	t_map			map;
}	t_data;


#endif