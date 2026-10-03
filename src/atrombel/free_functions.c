
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
		free(current_line);
	free_id(data);
	ft_gnl_flush(data->map.map_fd);
	if (data->map.map_fd >= 0)
		close(data->map.map_fd);
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
}