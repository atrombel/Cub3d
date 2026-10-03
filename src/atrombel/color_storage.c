

#include "cub3D.h"
#include "atrombel.h"

int	result_check(char *current_line, int *result, int i, bool *is_nbr)
{
	while(current_line[i] >= '0' && current_line[i] <= '9')
	{
		if (*is_nbr == false)
			*is_nbr = true;
		*result = *result * 10 + (current_line[i] - '0');
		if (*result > 255)
			return (i);
		i++;
	}
	return (i);
}

void	result_storage_f(t_data *data, bool *is_nbr, int *result, int *i)
{
		data->id.f[data->id.f_count] = *result;
		*is_nbr = false;
		*result = 0;
		data->id.f_count++;
		(*i)++;
}

int	color_storage_f(char *current_line, t_data *data, int i)
{
	int		result;
	bool	is_nbr;

	result = 0;
	is_nbr = false;
	while(data->id.f_count != 3)
	{
		i = space_newline_skipper(current_line, i);
		i = result_check(current_line, &result, i, &is_nbr);
		i = space_newline_skipper(current_line, i);
		if (!(result >= 0 && result <= 255))
			return (print_error_return("invalid F color\n", 1));
		if (current_line[i] == ',' && current_line[i] != '\0'
							&& data->id.f_count != 2 && is_nbr == true)
			result_storage_f(data, &is_nbr, &result, &i);
		else if (data->id.f_count == 2
			&& is_nbr == true
			&& (current_line[i] == '\0' || current_line[i] == '\n'))
			result_storage_f(data, &is_nbr, &result, &i);
		else
			return (print_error_return("invalid F color\n", 1));
	}
	return (0);
}

void	result_storage_c(t_data *data, bool *is_nbr, int *result, int *i)
{
		data->id.c[data->id.c_count] = *result;
		*is_nbr = false;
		*result = 0;
		data->id.c_count++;
		(*i)++;
}

int	color_storage_c(char *current_line, t_data *data, int i)
{
	int		result;
	bool	is_nbr;

	result = 0;
	is_nbr = false;
	while(data->id.c_count != 3)
	{
		i = space_newline_skipper(current_line, i);
		i = result_check(current_line, &result, i, &is_nbr);
		i = space_newline_skipper(current_line, i);
		if (!(result >= 0 && result <= 255))
			return (print_error_return("invalid C color\n", 1));
		if (current_line[i] == ',' && current_line[i] != '\0'
							&& data->id.c_count != 2 && is_nbr == true)
			result_storage_c(data, &is_nbr, &result, &i);
		else if (data->id.c_count == 2
			&& is_nbr == true
			&& (current_line[i] == '\0' || current_line[i] == '\n'))
			result_storage_c(data, &is_nbr, &result, &i);
		else
			return (print_error_return("invalid C color\n", 1));
	}
	return (0);
}
