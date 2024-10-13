#include "../../incs/cub3D.h"

static int		ext_check(char *file)
{
	int i;
	int fd;

	i = 0;
	fd = 0;
	while (file[i] != '.')
		i++;
	if (file[i + 1] != 'c' || file[i + 2] != 'u' || file[i + 3] != 'b'
		|| file[i + 4] != '\0')
	{
		print_error(INCORRECT_FILE);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(NO_FILE);
	return (fd);
}

static int	parse_line(int fd, t_meta *metadata)
{
	char	*ln;
	int		ln_nbr;

	ln_nbr = 0;
	ln = get_next_line(fd);
	while (ln)
	{
		if (ln_nbr <= 7)
		{
			if (parse_dir(metadata, ln, ln_nbr++))
				return (1);
		}
		else
		{
			if (parse_map(metadata, ln))
				return (1);
		}
		ln = get_next_line(fd);
	}
	free(ln);
	return (0);
}

/*
сама карта - проверить заливку, символы, N,S,E or W для игрока
*/
int		parse_input(char **argv, t_meta *metadata)
{
	int		fd;

	if ((fd = ext_check(argv[1])) < 0)
		return (1);
	if (parse_line(fd, metadata))
		return (1);
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	// if (check_map(metadata->map))
	// 	return (1);
	return (0);
}
