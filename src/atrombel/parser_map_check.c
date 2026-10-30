
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
	if (data->map.player_defined == false)
		return (print_error_return("No player found\n", 1));
	//if (flood_fill_map(data))
	return (0);
}