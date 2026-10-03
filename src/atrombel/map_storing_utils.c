
#include "cub3D.h"
#include "atrombel.h"

int	map_line_valid_chars_skipper(char *current_line, int i)
{
	while ((current_line[i] == ' '
			|| current_line[i] == '1'
			|| current_line[i] == '0'
			|| current_line[i] == 'N'
			|| current_line[i] == 'S'
			|| current_line[i] == 'E'
			|| current_line[i] == 'W')
		&& current_line[i] != '\0')
		i++;
	return (i);
}