
#include "cub3D.h"
#include "atrombel.h"

void	print_error(char *msg)
{
	write(2,"Error\n", 6);
	ft_putstr_fd(msg, 2);
}

void	print_error_precise(char *msg1, char *msg2)
{
	write(2,"Error\n", 6);
	ft_putstr_fd(msg1, 2);
	ft_putstr_fd(": ",2);
	ft_putstr_fd(msg2, 2);
}
