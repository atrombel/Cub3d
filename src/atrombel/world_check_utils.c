
#include "cub3D.h"
#include "atrombel.h"

int	world_f_check(char *current_line, int i, t_data *data)
{
	if (data->id.f_check_status == true)
	{
		print_error_precise("should be only one occurence of F", current_line + i);
		return (1);
	}
	i += 2;
	if (store_identifier_path(current_line, i, data, 4) == 1)
		return (1);
	data->id.f_check_status = true;
	return (0);
}

int	world_c_check(char *current_line, int i, t_data *data)
{
	if (data->id.c_check_status == true)
	{
		print_error_precise("should be only one occurence of C", current_line + i);
		return (1);
	}
	i += 2;
	if (store_identifier_path(current_line, i, data, 5) == 1)
		return (1);
	data->id.c_check_status = true;
	return (0);
}

bool	if_all_identifier_check(t_data *data)
{
	if (data->id.no_check_status == true
		&& data->id.so_check_status == true
		&& data->id.we_check_status == true
		&& data->id.ea_check_status == true
		&& data->id.f_check_status == true
		&& data->id.c_check_status == true)
		return (true);
	return (false);
}