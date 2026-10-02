
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

int	color_storage_f(char *current_line, t_data *data, int i)
{
	int	result;
	int	x;

	result = 0;
	x = 0;
	while (current_line[i])
	{
		if ((current_line[i] == ',' || current_line[i] == '\n') && x <= 2)
		{
			data->id.f[x] = result;
			if (result > 255)
				return (print_error_return("invalid F color\n", 1));
			result = 0;
			i++;
			x++;
			continue ;
		}
		if (current_line[i] < '0' || current_line[i] > '9')
			return (print_error_return("invalid F color\n", 1));
		result = result * 10 + (current_line[i] - '0');
		i++;
	}
	if (x != 3)
		return (print_error_return("invalid F color\n", 1));
	return (0);
}


///  A FAIRE CHECKER LS CAS VIDE EXEMPL
// F ,23,
// C 25, ,21
//TESTER 25,24,24, AVEC VIRUGLE A LA FIN
int	color_storage_c(char *current_line, t_data *data, int i)
{
	int	result;
	int	x;

	result = 0;
	x = 0;
	while (current_line[i])
	{
		if ((current_line[i] == ',' || current_line[i] == '\n') && x <= 2)
		{
			data->id.c[x] = result;
			if (result > 255)
				return (print_error_return("invalid C color\n", 1));
			result = 0;
			i++;
			x++;
			continue ;
		}
		if (current_line[i] < '0' || current_line[i] > '9')
			return (print_error_return("invalid C color\n", 1));
		result = result * 10 + (current_line[i] - '0');
		i++;
	}
	if (x != 3)
		return (print_error_return("invalid C color\n", 1));
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

	// printf("i = %d\n", i);
	// printf("current_line[i] = %c\n", current_line[i]);
	// printf("current_line[i -- ] = %c\n", current_line[i -3]);

	j = space_newline_skipper(current_line, i);

	j = find_next_whitespace(current_line, i);
	//printf("current_line[j] = %c\n", current_line[j]);

	j = space_newline_skipper(current_line, j);
	//printf("current_line[j] = %c\n", current_line[j]);
	if (current_line[j] != '\0' &&  current_line[j] != '\n')
	{
		print_error("Invalid characters after texture path\n");
		return (1);
	}
	else
	{
		current_line[j] = '\0';
		if (mode >= 0 && mode <= 3)
			return (id_storage_path_utils(current_line, data, mode));
		if (mode == 4 || mode == 5)
		{
			printf("color detected mode = %d\n", mode);
			return (color_storage_path_utils(current_line, data, i, mode));
		}
	}

	return (1);
}
