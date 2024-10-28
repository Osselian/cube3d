#include "../../incs/cub3D.h"

static int	flood_fill(char **map, int x, int y);

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

static int	flood_fill(char **map, int x, int y)
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

static int	*check_player(char **map, int *player_pos)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	printf(G"DEBUG: CHECKING PLAYER"RESET" %s %d\n", __FILE__, __LINE__);
	while (map && map[y] && map[y][x] && map[y][x] != '\0')
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E' ||
				map[y][x] == 'S')
			{
				if (player_pos[0] != -1)
				{
					print_error(MULTIPLE_PLAYERS);
					return (NULL);
				}
				else
				{
					player_pos[0] = y;
					player_pos[1] = x;
				}
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (!player_pos)
	{
		print_error(ZERO_PLAYERS);
		return (NULL);
	}
	return (player_pos);
}

int	check_map(char **map)
{
	int	player_pos[2];

	player_pos[0] = -1;
	if (check_player(map, player_pos) == NULL)
		return (1);
	printf(BLUE"DEBUG: CHECKED PLAYER"RESET" %s %d\n", __FILE__, __LINE__);
	if (flood_fill(map, player_pos[0], player_pos[1]))
		return (1);
	printf(BLUE"DEBUG: FLOODFILLED"RESET" %s %d\n", __FILE__, __LINE__);
	return (0);
}
