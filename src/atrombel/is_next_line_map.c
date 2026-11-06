
#include "cub3D.h"
#include "atrombel.h"


int	init_map(char *current_line, t_data *data)
{
	data->map.map_save = malloc(sizeof(char *) * 2);
	if (!data->map.map_save)
		return (print_error_precise("allocation failed", "2\n"), 1);
	data->map.map_save[0] = ft_strdup(current_line);
	if (!data->map.map_save[0])
	{
		free(data->map.map_save);
		data->map.map_save = NULL;
		return (print_error_precise("allocation failed", "2\n"), 1);
	}
	data->map.map_save[1] = NULL;
	data->map.line = 1;
	data->map.map_started = true;
	return (0);
}

int	is_next_line_map(char *current_line, t_data *data)
{
	int i;

	i = 0;
	printf("DEBUG current_line = %s\n", current_line);
	while ((current_line[i] == ' '
			|| current_line[i] == '1')
			&& (current_line[i] != '\0'))
		i++;
	if (i > 0 && (current_line[i] == '\0'
			|| current_line[i] == '\n'
			|| current_line[i] == '\r'))
		return (init_map(current_line, data));
	else
	{
		print_error_precise("invalid first map line", current_line);
		return (1);
	}
}

