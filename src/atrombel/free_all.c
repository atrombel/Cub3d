
#include "cub3D.h"
#include "atrombel.h"

void	free_all(t_data *data)
{
	free_map_save(data);
	free_id(data);
	if (data->map.map_fd >= 0)
		close(data->map.map_fd);
}
