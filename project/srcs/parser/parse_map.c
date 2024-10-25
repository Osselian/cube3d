#include "../../incs/cub3D.h"

static int	check_map_row(char *ln)
{
	unsigned int	i;

	i = 0;
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	while ((ln[i] != '\0' && ln[i] != '\n'))
	{
		if (i == INT_MAX)
		{
			print_error(LONGMAP);
			return (1);
		}
		if (!(ln[i] == '0' || ln[i] == '1' || ln[i] == 'N' ||
			ln[i] == 'W' || ln[i] == 'E' || ln[i] == 'S' || ln[i] == ' ' || ln[i] == 'D'))
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
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	if (check_map_row(ln))
		return (1);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	meta->map_str = ft_strjoin(meta->map_str, ln); //TODO в лист
	// ft_addline(meta->map, ln, &(meta->maplen));
	printf(G"DEBUG %s %d\n%s\n"RESET"\n", __FILE__, __LINE__, meta->map_str);
	return (0);
}
