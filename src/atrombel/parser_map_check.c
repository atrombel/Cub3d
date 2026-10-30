
#include "cub3D.h"
#include "atrombel.h"

int	parser_map_player_check(char *line, t_data *data, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W') && data->map.player_defined == true)
			return (print_error_return("redefinition of player found\n", 1));
		if (line[i] == 'N' || line[i] == 'S'
					|| line[i] == 'E' || line[i] == 'W')
		{
			data->map.player_x = i;
			data->map.player_y = y;
			data->map.player_defined = true;
		}
		i++;
	}
	if (!data->map.map_x_max)
		data->map.map_x_max = i - 1;
	else
	{
		if (i > data->map.map_x_max)
			data->map.map_x_max = i - 1;
	}
	return (0);
}
char	**map_copy(char **map)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (map[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tmp[j] = ft_strdup(map[j]);
		if (!tmp[j])
		{
			while (j > 0)
				free(tmp[--j]);
			free(tmp);
			return (NULL);
		}
		j++;
	}
	tmp[j] = NULL;
	return (tmp);
}

void	free_char_array(char	**map_tmp)
{
	int	i;

	i = 0;
	while (map_tmp[i])
	{
		free(map_tmp[i]);
		i++;
	}
	free (map_tmp);
}

int	map_flood_check(t_data *data)
{
	char	**map_tmp;

	map_tmp = map_copy(data->map.map_save);
	if (!map_tmp)
		return (print_error_return("map allocation failed\n", 1));
	data->map.map_flood_valid = true;
	flood_fill_map(data, data->map.player_x,
		data->map.player_y, map_tmp);
	free_char_array(map_tmp);
	if (data->map.map_flood_valid == false)
		return (1);
	return (0);
}

int	parser_map_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map_save[i])
	{
		if (parser_map_player_check(data->map.map_save[i], data, i))
			return (1);
		i++;
	}
	data->map.map_y_max = i - 1;
	if (data->map.player_defined == false)
		return (print_error_return("No player found\n", 1));
	if (map_flood_check(data) == 1)
		return (1);
	return (0);
}
