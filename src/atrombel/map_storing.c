
#include "cub3D.h"
#include "atrombel.h"

int map_storing(char *current_line, t_data *data)
{
	data->map.map_save[data->map.line] = ft_strdup(current_line);
	if (!data->map.map_save)
		return (1);
	data->map.line++;
	return (0);
}