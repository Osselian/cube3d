#include "../../incs/cub3D.h"

int		ext_check(char *file)
{
	int i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (file[i + 1] != 'c' || file[i + 2] != 'u' || file[i + 3] != 'b'
		|| file[i + 4] != '\0')
	{
		print_error("Incorrect file type\n");
		return (-1);
	}
	return (open(file, O_RDONLY));
}

/*
- проверить экст
- NO (./path_to_the_north_texture или цвет)
- SO (./path_to_the_south_texture или цвет)
- WE (./path_to_the_west_texture или цвет)
- EA (./path_to_the_east_texture или цвет)

- F 220,100,0 (./path_to_the_floor_texture или цвет)
- C 225,30,0 (./path_to_the_ceiling_texture или цвет)

сама карта - проверить заливку, символы, N,S,E or W для игрока
*/
int		parse_input(char **argv, t_meta *metadata)
{
	int		fd;
	char	*line;

	if ((fd = ext_check(argv[1])) < 0)
		return (0);
	parse_txtrs(argv, metadata);

	print_error("DEBUG\n");
	return (1);
}
