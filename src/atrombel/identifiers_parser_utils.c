
#include "cub3D.h"
#include "atrombel.h"

int	no_id_storage_path(char *current_line, t_data *data, int i)
{
	int j;

	j = space_newline_finder(current_line, i);
	j = space_newline_skipper(current_line, j);
	if (current_line[j] != '\0')
	{
		print_error("Invalid characters after NO texture path\n");
		return (1);
	}
	else
	{
		current_line[j] = '\0';
		data->id.no_path = ft_strdup(current_line);
		if (!data->id.no_path)
		{
			print_error("strdup, malloc failed in no_id_storage_path\n");
			return (1);
		}
		return (0);
	}
}