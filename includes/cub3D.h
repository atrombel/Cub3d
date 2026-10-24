/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:54:50 by atrombel          #+#    #+#             */
/*   Updated: 2026/10/22 16:20:44 by cgasser          ###   ####lausanne.ch   */
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
# include "mlx.h"
# include <math.h>
# include "keycodes.h"
# include "color.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define PLAYER_SPEED 0.004
# define PLAYER_ROT_SPEED 0.002

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
	int		f_count;
	bool	f_check_status;// a utilsie r comme pour le c eviter et tser les
	int		c[3];
	int		c_count;
	bool	c_check_status;

} t_identifier;

// line is the nuber of line from line 0 to line x of the mab
typedef struct s_map
{
	int		line;
	char	**map_save;
	int	dim[2];//[width, height]
	bool	map_started;
	bool	map_ended;
	bool	ismap_stored;
	int		map_fd;// TO CLOSE
}	t_map;

//mlx image settings
typedef struct s_img
{
	void	*ptr; //img_ptr
	char	*addr; //img_address
	int		bpp; //bits_per_pixel
	int		sl; //size_line
	int		en; //endian
	int		wh; //width
	int		ht; //height
}	t_img;

//display settings
typedef struct s_display
{
	void	*mlx_ptr; //mlx objet ptr
	void	*win_ptr; //window ptr
	t_img	frame;//frame (mlx image pushed to the window)
	int	scale;//scale factor between the map and the frame
}	t_display;

//player settings
typedef struct s_player
{
	double	pos[2];//[x, y]
	double	angle;//player angle
	float	speed_cos;//player speed in x
	float	speed_sin;//player speed in y
}	t_player;

typedef struct s_data
{
	t_identifier	id;
	t_map			map;
	t_display		display;
	t_player		player;
}	t_data;


#endif
