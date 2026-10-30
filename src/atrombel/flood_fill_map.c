
#include "cub3D.h"
#include "atrombel.h"


int	flood_utils(t_data *data, int x, int y, char **map)
{
	if ((data->map.map_flood_valid == false)
		|| ((y == 0 && map[y][x] == '0'))
		|| (map[y][x] != '0' && map[y][x] != '1'
		&& map[y][x] != 'N' && map[y][x] != 'S'
		&& map[y][x] != 'E' && map[y][x] != 'W' && map[y][x] != 'x')
		|| (y == data->map.map_y_max && map[y][x] == '0')
		|| (x == 0 && map[y][x] == '0'))
	{
		data->map.map_flood_valid = false;
		if (map[y][x] == '\0')
			printf("Error\nInvalid map, index line %d and column %d, char '\\0'\n",
				y, x);
		else
			printf("Error\nInvalid map, index line %d and column %d, char '%c'\n",
		y, x, map[y][x]);
		return (1);
	}
	return (0);
}
void	flood_fill_map(t_data *data, int x, int y, char **map)
{
	if (data->map.map_flood_valid == false)
		return ;
	if (x < 0 || y < 0 || y > data->map.map_y_max || x > (int)ft_strlen(map[y]))
	{
		data->map.map_flood_valid = false;
		printf("Error\nInvalid map, outside map at line %d column %d\n", y, x);
		return ;
	}
	if (flood_utils(data, x, y, map))
		return ;
	if ((map[y][x] == '1') || (map[y][x] == 'x'))
		return ;
	map[y][x] = 'x';
	flood_fill_map(data, x + 1, y, map);
	flood_fill_map(data, x - 1, y, map);
	flood_fill_map(data, x, y + 1, map);
	flood_fill_map(data, x, y - 1, map);
}

