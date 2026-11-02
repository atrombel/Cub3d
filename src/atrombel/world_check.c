
#include "cub3D.h"
#include "atrombel.h"

int	world_no_check(char *current_line, int i, t_data *data)
{
	int	tmp_fd;

	if (data->id.no_check_status == true)
	{
		print_error_precise("should be only one occurence of NO\n", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 0) == 1)
		return (1);
	if (ft_reverse_strncmp_verif(data->id.no_path, ".xpm") != 0)
	{
		print_error("texture NO file format invalid, must be .xpm\n");
		return (1);
	}
	tmp_fd = open(data->id.no_path, O_RDONLY);
	if (tmp_fd < 0)
	{
		print_error_precise("invalid NO texture path", current_line + i);
		return (1);
	}
	close(tmp_fd);
	data->id.no_check_status = true;
	return (0);
}

int	world_so_check(char *current_line, int i, t_data *data)
{
	int	tmp_fd;

	if (data->id.so_check_status == true)
	{
		print_error_precise("should be only one occurence of SO", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 1) == 1)
		return (1);
	if (ft_reverse_strncmp_verif(data->id.so_path, ".xpm") != 0)
	{
		print_error("texture SO file format invalid, must be .xpm\n");
		return (1);
	}
	tmp_fd = open(data->id.so_path, O_RDONLY);
	if (tmp_fd < 0)
	{
		print_error_precise("invalid SO texture path", current_line + i);
		return (1);
	}
	close(tmp_fd);
	data->id.so_check_status = true;
	return (0);
}
int	world_we_check(char *current_line, int i, t_data *data)
{
	int	tmp_fd;

	if (data->id.we_check_status == true)
	{
		print_error_precise("should be only one occurence of WE", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 2) == 1)
		return (1);
	if (ft_reverse_strncmp_verif(data->id.we_path, ".xpm") != 0)
	{
		print_error("texture WE file format invalid, must be .xpm\n");
		return (1);
	}
	tmp_fd = open(data->id.we_path, O_RDONLY);
	if (tmp_fd < 0)
	{
		print_error_precise("invalid WE texture path", current_line + i);
		return (1);
	}
	close(tmp_fd);
	data->id.we_check_status = true;
	return (0);
}

int	world_ea_check(char *current_line, int i, t_data *data)
{
	int	tmp_fd;

	if (data->id.ea_check_status == true)
	{
		print_error_precise("should be only one occurence of EA", current_line + i);
		return (1);
	}
	i += 3;
	if (store_identifier_path(current_line, i, data, 3) == 1)
		return (1);
	if (ft_reverse_strncmp_verif(data->id.ea_path, ".xpm") != 0)
	{
		print_error("texture EA file format invalid, must be .xpm\n");
		return (1);
	}
	tmp_fd = open(data->id.ea_path, O_RDONLY);
	if (tmp_fd < 0)
	{
		print_error_precise("invalid EA texture path", current_line + i);
		return (1);
	}
	close(tmp_fd);
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
