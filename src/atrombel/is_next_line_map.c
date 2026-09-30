
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
		//copy first line of map dans un char**;
		data->map.map_started = true;
		return (true);
	}
	else
	{
		print_error_precise("the first line of the map after identifiers should be only walls or space", current_line);
		return (false);
	}
}