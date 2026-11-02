/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgasser <cgasser@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:12:59 by cgasser           #+#    #+#             */
/*   Updated: 2026/11/02 12:13:09 by cgasser          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "cgasser.h"

int	ft_abs_int(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max_int(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}


