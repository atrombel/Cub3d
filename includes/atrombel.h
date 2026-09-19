/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atrombel.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrombel <atrombel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 13:56:00 by atrombel          #+#    #+#             */
/*   Updated: 2026/09/18 13:56:02 by atrombel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATROMBEL_H
# define ATROMBEL_H

//parsing
int		arguments_nbr_check(int argc);
int		parser_main(t_data *data, char *path_to_map);
int		parser_map_file_type_check(char *path_to_map);

//error msg
void	print_error(char *msg);


#endif