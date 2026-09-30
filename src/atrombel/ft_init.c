
#include "cub3D.h"
#include "atrombel.h"

void	ft_init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map.map_fd = -1;
}
