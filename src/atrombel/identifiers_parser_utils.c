
#include "cub3D.h"
#include "atrombel.h"

int	id_storage_path_utils(char *current_line, t_data *data, int mode)
{
	if (mode == 0)
	{
		data->id.no_path = ft_strdup(current_line);
		if (!data->id.no_path)
			return(print_error_return("strdup, malloc failed in id_storage_path\n", 1));
	}
	if (mode == 1)
	{
		data->id.so_path = ft_strdup(current_line);
		if (!data->id.so_path)
			return(print_error_return("strdup, malloc failed in id_storage_path\n", 1));
	}
	if (mode == 2)
	{
		data->id.we_path = ft_strdup(current_line);
		if (!data->id.we_path)
			return(print_error_return("strdup, malloc failed in id_storage_path\n", 1));
	}
	if (mode == 3)
	{
		data->id.ea_path = ft_strdup(current_line);
		if (!data->id.ea_path)
			return(print_error_return("strdup, malloc failed in id_storage_path\n", 1));
	}
	return (0);
}






int	color_storage_path_utils(char *current_line, t_data *data, int i, int mode)
{
	if (mode == 4)
		return (color_storage_f(current_line, data, i));
	if (mode == 5)
		return (color_storage_c(current_line, data, i));
	return (1);
}
//
int	id_storage_path(char *current_line, t_data *data, int i, int mode)
{
	int	j;

	j = space_newline_skipper(current_line, i);
	if (mode >= 0 && mode <= 3)
	{
		j = find_next_whitespace(current_line, j);
		if (current_line[j] == '\0')
			return (id_storage_path_utils(current_line, data, mode));
		current_line[j] = '\0';
		j++;
		j = space_newline_skipper(current_line, j);
		if (current_line[j] != '\0' &&  current_line[j] != '\n')
		{
			print_error("Invalid characters after texture path\n");
			return (1);
		}
		return (id_storage_path_utils(current_line, data, mode));
	}
	else
	{
		j = space_newline_skipper(current_line, i);
		if (current_line[j] == '\0')
			return (print_error_mode("invalid color missing\n", mode), 1);
		return (color_storage_path_utils(current_line, data, i, mode));
	}
}

