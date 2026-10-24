/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:13:31 by cgasser           #+#    #+#             */
/*   Updated: 2026/10/23 15:17:00 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_is_player(char c)
{
	if (c == 'E')
		return (c);
	if (c == 'W')
		return (c);
	if (c == 'N')
		return (c);
	if (c == 'S')
		return (c);
	return (0);
}
