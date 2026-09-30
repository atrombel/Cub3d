
#include "cub3D.h"
#include "atrombel.h"

bool	is_next_line_map(char *current_line, t_data *data)
{
	int i;

	i = 0;
	while ((current_line[i] == ' '
			|| current_line[i] == '1')
			&& (current_line[i] != '\0'))
		i++;
	if ((current_line[i] == '\0' || current_line[i] == '\n'))
	{
		data->map.map_save[data->map.line] = ft_strdup(current_line);
		if (!data->map.map_save)
			return (false);
		data->map.line = 1;
		data->map.map_started = true;
		return (true);
	}
	else
	{
		print_error_precise("the first line of the map after identifiers should be only walls or space", current_line);
		return (false);
	}
}