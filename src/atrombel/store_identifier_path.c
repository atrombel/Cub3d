
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
		// printf("1 i = %d\n", i);

	i = space_newline_skipper(current_line, i);
		// printf("2 i = %d\n", i);
		// printf("2 current_line[i] = %c\n", current_line[i]);
		// printf("2 current_line[i + 1] = %c\n", current_line[i + 1]);
				// printf("-----------\n");


	if (current_line[i] == '\0')
	{
		print_error("at least one texture path is absent\n");
		return (1);
	}
	return (id_storage_path(current_line, data, i, mode));
}