/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 09:32:27 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 09:32:51 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

double	get_time(void);
void	update_delta_time(t_data *data);

int	ft_key_press(int key, t_data *data)
{
	if (key == K_W)
		data->keys.w = 1;
	if (key == K_S)
		data->keys.s = 1;
	if (key == K_A)
		data->keys.a = 1;
	if (key == K_D)
		data->keys.d = 1;
	if (key == K_LEFT)
		data->keys.left = 1;
	if (key == K_RIGHT)
		data->keys.right = 1;
	if (key == K_ESC)
		data->keys.esc = 1;
	return (0);
}

int	ft_key_release(int key, t_data *data)
{
	if (key == K_W)
		data->keys.w = 0;
	if (key == K_S)
		data->keys.s = 0;
	if (key == K_A)
		data->keys.a = 0;
	if (key == K_D)
		data->keys.d = 0;
	if (key == K_LEFT)
		data->keys.left = 0;
	if (key == K_RIGHT)
		data->keys.right = 0;
	if (key == K_ESC)
		data->keys.esc = 0;
	return (0);
}

int	ft_loop_hook(t_data *data)
{
	if (data->keys.esc)
		return (ft_kill_mlx(data), 0);
	update_delta_time(data);

	ft_update_rotation(data);
	ft_update_movement(data);

	render_frame(data);

	return (0);
}

double	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec + tv.tv_usec / 1000000.0);
}

void	update_delta_time(t_data *data)
{
	double	current;

	current = 0;
	current = get_time();
	data->time.delta_time = current - data->time.last_time;
	data->time.last_time = current;
}
