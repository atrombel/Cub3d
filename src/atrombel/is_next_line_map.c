
#include "cub3D.h"
#include "atrombel.h"

int	is_next_line_map(char *current_line, t_data *data)
{
	int i;

	i = 0;
	while ((current_line[i] == ' '
			|| current_line[i] == '1')
			&& (current_line[i] != '\0'))
		i++;
	if ((current_line[i] == '\0' || current_line[i] == '\n'))
	{
		data->map.map_save = malloc(sizeof(char *) * 2);
		if (!data->map.map_save)
			return (print_error_precise("allocation failed", "2\n"), 1);
		data->map.map_save[data->map.line] = ft_strdup(current_line);
							printf("map_save[%d] = %s\n", data->map.line, data->map.map_save[data->map.line]);

		data->map.map_save[1] = NULL;
		if (!data->map.map_save)
			return (print_error_precise("allocation failed", "2\n"), 1);
		data->map.line = 1;
		data->map.map_started = true ;
		return (0);
	}
	else
	{
		print_error_precise("invalid first map line", current_line);
		return (1);
	}
}

