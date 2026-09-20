
#include "cub3D.h"
#include "atrombel.h"

int	store_identifier_path(char *current_line)
{
	(void)current_line;
	return (0);

}

int	word_check(char *current_line, int i)
{
	if(ft_strncmp("NO ", current_line + i, 3) == 0)
	{
		if (store_identifier_path(current_line + i) == 1)
			return (1);
		return (0);
	}
	return (1);
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
		while (current_line[i])
		{
			i = space_newline_skipper(current_line, i);
			if (current_line[i] == '\0')
				break ;
			if (word_check(current_line, i))
				return (1);
			i++;
		}
		free(current_line);
	}
	return (0);
}