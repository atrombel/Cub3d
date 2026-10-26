
#include "cub3D.h"
#include "atrombel.h"

int find_next_whitespace(char *current_line, int i)
{
	while (!((current_line[i] == ' ' || current_line[i] == '\r'
			|| current_line[i] == '\t' || current_line[i] == '\v'
			|| current_line[i] == '\f' || current_line[i] == '\n'))
			&& (current_line[i] != '\0'))
		i++;
	return (i);
}

int space_newline_skipper(char *current_line, int i)
{
	while ((current_line[i] == ' ' || current_line[i] == '\r'
			|| current_line[i] == '\t' || current_line[i] == '\v'
			|| current_line[i] == '\f' || current_line[i] == '\n')
			&& (current_line[i] != '\0'))
		i++;
	return (i);
}

int	parser_identifier_check(t_data *data)
{
	char	*current_line;
	int		i;

	while ((current_line = get_next_line(data->map.map_fd)))
	{
		if (!current_line && (data->map.ismap_stored == true))
			return (ft_gnl_flush(data->map.map_fd), 0);
		if (data->map.map_started == true)
		{
			if (map_storing(current_line, data) == 1)
				return (ft_gnl_flush(data->map.map_fd), parser_cleanup_error(data, current_line), 1);
			if (data->map.map_ended == 1)
				return (ft_gnl_flush(data->map.map_fd), free(current_line), 0);
			free(current_line);
			continue ;
		}
		i = 0;
		i = space_newline_skipper(current_line, i);
		if (word_check(current_line, i, data))
			return (parser_cleanup_error(data, current_line), 1);
		free(current_line);
	}
	return (0);
}
