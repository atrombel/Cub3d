
#include "cub3D.h"
#include "atrombel.h"


void	print_error(char *msg)
{
	write(2,"Error\n", 6);
	ft_putstr_fd(msg, 2);
}