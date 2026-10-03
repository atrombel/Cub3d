
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

int	print_error_return(char *msg, int value)
{
	write(2,"Error\n", 6);
	ft_putstr_fd(msg, 2);
	return(value);
}


void	print_error_mode(char *msg, int mode)
{
	char	*id_name[6];

	id_name[0] = "NO";
	id_name[1] = "SO";
	id_name[2] = "WE";
	id_name[3] = "EA";
	id_name[4] = "F";
	id_name[5] = "C";

	write(2, "Error\n", 6);
	ft_putstr_fd(id_name[mode], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
}
