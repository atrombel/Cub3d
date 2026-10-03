
#include "cub3D.h"
#include "atrombel.h"

int	ft_reverse_strncmp_cub_verif(char *s1, char *s2)
{
	size_t	i;
	int		j;

	j = 3;
	i = ft_strlen(s1);
	while (i > 0 && j >= 0)
	{
		if (s1[i - 1] != s2[j])
			return ((unsigned char)s1[i - 1] - (unsigned char)s2[j]);
		i--;
		j--;
	}
	if (j == -1)
		return (0);
	return (1);
}

int	parser_file_type_check(char *path_to_map)
{
	if (ft_reverse_strncmp_cub_verif(path_to_map, ".cub") != 0)
	{
		print_error("file format invalid, must be .cub\n");
		return (1);
	}
	return (0);
}

int	parser_map_open_check(char *path_to_map, t_data *data)
{
	data->map.map_fd = open(path_to_map, O_RDONLY);
	if (data->map.map_fd >= 0)
		return (0);
	else
	{
		print_error("Cannot open map file\n");
		return (1);
	}
}

int	arguments_nbr_check(int argc)
{
	if (argc != 2)
	{
		print_error("required format is ./cub3D <path_to_map>\n");
		return (1);
	}
	return (0);
}
