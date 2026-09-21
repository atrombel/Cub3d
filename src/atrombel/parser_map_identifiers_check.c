
#include "cub3D.h"
#include "atrombel.h"

int	store_identifier_path(char *current_line, int i, t_data *data, int mode)
{
	i = space_newline_skipper(current_line + i, i);
	if (current_line[i] == '\0')
	{
		print_error("at least one texture path is absent\n");
		return (1);
	}
	if (mode == 0)
		return (no_id_storage_path(current_line, data, i));
	return (0);

}

int	word_check(char *current_line, int i, t_data *data)
{
	if(ft_strncmp("NO ", current_line + i, 3) == 0)
	{
		i += 3;
		if (store_identifier_path(current_line, i, data, 0) == 1)
			return (1);
		data->id.no_check_status = true;
		return (0);
	}
	print_error_precise("invalid identifier detected", current_line + i);
	return (1);
}

int space_newline_finder(char *current_line, int i)
{
	while (!((current_line[i] == ' ' || current_line[i] == '\r'
			|| current_line[i] == '\t' || current_line[i] == '\v'
			|| current_line[i] == '\f' || current_line[i] == '\n')
			&& (current_line[i] != '\0')))
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
		i = 0;
		i = space_newline_skipper(current_line, i);
		if (current_line[i] == '\0')
			continue ;
		if (word_check(current_line, i, data))
			return (free(current_line), free_id(data), 1);
		free(current_line);
	}

	printf("\033[0;32m[SIGNALISATION]yo\033[0m\n");
	//if (data->id.all_id_check_status == true)
	return (0);
	//return (1);
}