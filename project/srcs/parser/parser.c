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
	long	ln_nbr;

	ln_nbr = 0;
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	ln = get_next_line(fd);
	while (ln && *ln)
	{
		if (ln_nbr <= 7)
		{
			if (parse_dir(metadata, ln, ln_nbr))
			{
				printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
				return (1);
			}
			printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
		}
		else
		{
			printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
			if (ln_nbr - 7 == INT_MAX)
			{
				printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
				print_error(LONGMAP);
				printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
				return (1);
			}
			if (parse_map(metadata, ln))
			{
				printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
				return (1);
			}
			printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
		}
		printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
		ln_nbr++;
		printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
		ln = get_next_line(fd);
	}
	free(ln);
	return (0);
}

int		parser(char **argv, t_meta *metadata)
{
	int		fd;

	if ((fd = ext_check(argv[1])) < 0)
		return (1);
	printf(BLUE"DEBUG: CHECKED EXTENTION"RESET" %s %d\n", __FILE__, __LINE__);
	if (parse_line(fd, metadata))
		return (1);
	if (check_map(metadata->map))
		return (1);
	printf(BLUE"DEBUG: CHECKED MAP"RESET" %s %d\n", __FILE__, __LINE__);
	return (0);
}
