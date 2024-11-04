#include "../../incs/cub3D.h"

int	flood_fill(char **map, int x, int y);

static int	flood_fill_helper(char **map, int x, int y)
{
	if (!map || !map[x] || !map[x][y] || map[x][y] == '\0' || map[x][y] == ' ')
	{
		return (print_error(BADMAP));
	}
	else if (map[x][y] == 's')
		return (0);
	else if (map[x][y] != '1')
	{
		if (map[x][y] == '0')
			map[x][y] = 's';
		return(flood_fill(map, x, y));
	}
	return (0);
}

int	flood_fill(char **map, int x, int y)
{
	if (flood_fill_helper(map, x, y + 1))
		return (1);
	if (flood_fill_helper(map, x, y - 1))
		return (1);
	if (flood_fill_helper(map, x + 1, y))
		return (1);
	if (flood_fill_helper(map,  x - 1, y))
		return (1);
	return (0);
}
