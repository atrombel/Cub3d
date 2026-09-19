

#include "cub3D.h"
#include "atrombel.h"


int	arguments_nbr_check(int argc)
{
	if (argc != 2)
	{
		print_error("required format is ./cub3D <path_to_map>\n");
		return (1);
	}
	return (0);
}