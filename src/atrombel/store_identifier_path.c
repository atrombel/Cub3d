
#include "cub3D.h"
#include "atrombel.h"

//mode 0 = NO
//mode 1 = SO
//mode 2 = WE
//mode 3 = EA
//mode 4 = F
//mode 5 = C
int	store_identifier_path(char *current_line, int i, t_data *data, int mode)
{
	i = space_newline_skipper(current_line + i, i);
	if (current_line[i] == '\0')
	{
		print_error("at least one texture path is absent\n");
		return (1);
	}
	return (id_storage_path(current_line, data, i, mode));
}