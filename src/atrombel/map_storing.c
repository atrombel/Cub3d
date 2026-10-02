
#include "cub3D.h"
#include "atrombel.h"

void	maps_tmp_swap(char **tmp, char **map_save)
{
	int	i;

	i = 0;
	if (!tmp)
		return ;
	while(tmp[i])
	{
		map_save[i] = tmp[i];
		i++;
	}
	free(tmp);
}
int	map_expand_and_add_line(char *current_line, t_data *data)
{
	char	**tmp;

	tmp = data->map.map_save;
	data->map.map_save = malloc(sizeof(char *) * (data->map.line + 2));
	if (!data->map.map_save)
	if (!data->map.map_save)
	{
		data->map.map_save = tmp;
		free_map_save(data);
		print_error("map allocation failed\n");
		return (1);
	}
	maps_tmp_swap(tmp, data->map.map_save);
	data->map.map_save[data->map.line] = ft_strdup(current_line);
	if (!data->map.map_save[data->map.line])
	{
		free_map_save(data);
		print_error("map allocation failed\n");
		return (1);
	}
	data->map.map_save[data->map.line + 1] = NULL;
	data->map.line ++;
	return (0);
}

int map_storing(char *current_line, t_data *data)
{
	int		i;

	i = 0;
	i = map_line_valid_chars_skipper(current_line, i);
	if ((current_line[i] == '\0' || current_line[i] == '\n'))
	{
		if (map_expand_and_add_line(current_line, data) == 1)
		{
			printf("map_storing error \n");
			return (1);
		}
	}
	else
	{
		print_error_precise("invalid first map line", current_line);
		return (free_map_save(data), 1);
	}
	return (0);
}
