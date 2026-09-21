
#include "cub3D.h"
#include "atrombel.h"

void	free_id(t_data *data)
{
	if (data->id.no_path)
		free(data->id.no_path);
	if (data->id.so_path)
		free(data->id.so_path);
	if (data->id.we_path)
		free(data->id.we_path);
	if (data->id.ea_path)
		free(data->id.ea_path);
}