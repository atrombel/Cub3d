
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

int	parser_map_file_type_check(char *path_to_map)
{
	if (ft_reverse_strncmp_cub_verif(path_to_map, ".cub") != 0)
	{
		print_error("file format invalid, must be .cub\n");
		return (1);
	}
	return (0);
}