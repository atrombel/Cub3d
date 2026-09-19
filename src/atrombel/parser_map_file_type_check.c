
#include "cub3D.h"
#include "atrombel.h"

int	ft_reverse_strncmp_cub_verif(char *s1, char *s2)
{
	int	i;
	int	j;
	int	n;

	n = 4;
	j = 3;
	i = ft_strlen(s1) - 1;
	while (n > 0 && i >= 0 && j >= 0)
	{
		if (s1[i] != s2[j])
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		n--;
		i--;
		j--;
	}
	if (n == 0)
		return (0);
	return (1);
}

int	parser_map_file_type_check(char *path_to_map)
{
	if (ft_reverse_strncmp_cub_verif(path_to_map, ".cub") != 0)
		return (1);
	return (0);
}