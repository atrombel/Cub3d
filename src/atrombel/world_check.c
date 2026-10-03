
#include "cub3D.h"
#include "atrombel.h"

int	world_no_check(char *current_line, int i, t_data *data)
{

	if (data->id.no_check_status == true)
	{
		print_error_precise("should be only one occurence of NO", current_line + i);
		return (1);
	}
	i += 3;
			printf("no the current_line = %s", current_line);
		printf("0 i = %d\n", i);

	if (store_identifier_path(current_line, i, data, 0) == 1)
		return (1);
	data->id.no_check_status = true;
	return (0);
}

int	world_so_check(char *current_line, int i, t_data *data)
{

	if (data->id.so_check_status == true)
	{
		print_error_precise("should be only one occurence of SO", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 1) == 1)
		return (1);
	data->id.so_check_status = true;
	return (0);
}
int	world_we_check(char *current_line, int i, t_data *data)
{
	if (data->id.we_check_status == true)
	{
		print_error_precise("should be only one occurence of WE", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 2) == 1)
		return (1);
	data->id.we_check_status = true;
	return (0);
}

int	world_ea_check(char *current_line, int i, t_data *data)
{
	if (data->id.ea_check_status == true)
	{
		print_error_precise("should be only one occurence of EA", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 3) == 1)
		return (1);
	data->id.ea_check_status = true;
	return (0);
}


int	word_check(char *current_line, int i, t_data *data)
{
	if (current_line[i] == '\0' || current_line[i] == '\n')
		return (0);
	if(ft_strncmp("NO ", current_line + i, 3) == 0)
		return (world_no_check(current_line, i , data));
	if(ft_strncmp("SO ", current_line + i, 3) == 0)
		return (world_so_check(current_line, i , data));
	if(ft_strncmp("WE ", current_line + i, 3) == 0)
	 	return (world_we_check(current_line, i , data));
	if(ft_strncmp("EA ", current_line + i, 3) == 0)
		return (world_ea_check(current_line, i , data));
	if(ft_strncmp("F ", current_line + i, 2) == 0)
	 	return (world_f_check(current_line, i , data));
	if(ft_strncmp("C ", current_line + i, 2) == 0)
		return (world_c_check(current_line, i , data));
	if (if_all_identifier_check(data) == true)
	{
		if (is_next_line_map(current_line, data) == 0)
			return (0);
		else
			return (1);
	}
	print_error_precise("invalid identifier detected", current_line + i);
	return (1);
}
