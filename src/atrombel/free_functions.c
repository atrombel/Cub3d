
#include "cub3D.h"
#include "atrombel.h"

void	free_id(t_data *data)
{
	free(data->id.no_path);
	data->id.no_path = NULL;
	free(data->id.so_path);
	data->id.so_path = NULL;
	free(data->id.we_path);
	data->id.we_path = NULL;
	free(data->id.ea_path);
	data->id.ea_path = NULL;
}

void	ft_gnl_flush(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}
int	parser_cleanup_error(t_data *data, char *current_line)
{
	if (current_line)
	{
		free(current_line);
		current_line = NULL;
	}
	free_id(data);
	ft_gnl_flush(data->map.map_fd);
	if (data->map.map_fd >= 0)
		close(data->map.map_fd);
	data->map.map_fd = -1;
	return (1);
}

void	free_map_save(t_data *data)
{
	int	i;

	if (!data->map.map_save)
		return ;
	i = 0;
	while (data->map.map_save[i])
	{
		free(data->map.map_save[i]);
		i++;
	}
	free(data->map.map_save);
	data->map.map_save = NULL;
	data->map.line = 0;
}

void	free_all(t_data *data)
{
	free_map_save(data);
	free_id(data);
	if (data->map.map_fd >= 0)
		close(data->map.map_fd);
	data->map.map_fd = -1;
}