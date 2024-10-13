#include "../../incs/cub3D.h"

static int	check_map_row(char *ln)
{
	int	i;

	i = 0;
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	while (!(ln[i] == '\0' || ln[i] == '\n'))
	{
		if (!(ln[i] == '0' || ln[i] == '1' || ln[i] == 'N' ||
			ln[i] == 'W' || ln[i] == 'E' || ln[i] == 'S' || ln[i] == ' '))
		{
			print_error(INCORRECT_MAP_SYMBOL);
			return (1);
		}
		i++;
	}
	return (0);
}

int	parse_map(t_meta *meta, char *ln)
{
	if (check_map_row(ln))
		return (1);
	ft_addline(meta->map, ln);
	return (0);
}
