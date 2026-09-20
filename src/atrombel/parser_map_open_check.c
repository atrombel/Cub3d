
#include "cub3D.h"
#include "atrombel.h"

int	parser_map_open_check(char *path_to_map, t_data *data)
{
	data->map.map_fd = open(path_to_map, O_RDONLY);
	if (data->map.map_fd >= 0)
		return (0);
	else
	{
		print_error("Cannot open map file\n");
		return (1);
	}
}
