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
int		parser_map_open_check(char *path_to_map, t_data *data);
int		parser_map_identifiers_check(t_data *data);
int		id_storage_path(char *current_line, t_data *data, int i, int mode);
int		id_storage_path_utils(char *current_line, t_data *data, int mode);
int		space_newline_skipper(char *current_line, int i);
int		find_next_whitespace(char *current_line, int i);
int		word_check(char *current_line, int i, t_data *data);
int		world_f_check(char *current_line, int i, t_data *data);
int		world_c_check(char *current_line, int i, t_data *data);
int		store_identifier_path(char *current_line, int i, t_data *data, int mode);
bool	if_all_identifier_check(t_data *data);
bool	is_next_line_map(char *current_line, t_data *data);


//error msg
void	print_error(char *msg);
void	print_error_precise(char *msg1, char *msg2);
int		print_error_return(char *msg, int value);


// free functions
void	free_id(t_data *data);


#endif