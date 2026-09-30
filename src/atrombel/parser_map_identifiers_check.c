
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

int	parser_map_identifiers_check(t_data *data)
{
	char	*current_line;
	int		i;

	while ((current_line = get_next_line(data->map.map_fd)))
	{
		if (data->map.map_started == true)// to implementa
			return (0);// changer le return 0 par une fonction qui stocke la map dans un cahr ** puis continue;
		i = 0;
		i = space_newline_skipper(current_line, i);
		if (word_check(current_line, i, data))
			return (free(current_line), free_id(data), 1);
		free(current_line);
	}
	printf("\033[0;32m[SIGNALISATION]yo\033[0m\n");
	return (1);
}