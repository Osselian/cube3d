#include "../../incs/cub3D.h"

int		ext_check(char *file)
{
	while (*file != '.')
		*file++;
	if (ft_strncmp(*file, "cub", 4))
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
	// while (get_next_line(fd, &line) && metadata->valid == 1)
	// {
	// 	if (!parse_infos(metadata, line))
	// 		return (0);
	// 	free(line);
	// }
	// if (!(parse_infos(metadata, line)))
	// 	return (0);
	// free(line);
	// if (!check_info(metadata))
	// 	return (0);
	// if (argv[2] && ft_strncmp(av[2], "--save", 6) == 0 && ft_strlen(argv[2]) == 6)
	// 	metadata->save = 1;
	print_error("DEBUG\n");
	return (1);
}
