#include "../../incs/cub3D.h"

static int	flood_fill(char **map, int x, int y);

static int	flood_fill_helper(char **map, int x, int y)
{
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (!map || !map[x] || !map[x][y] || map[x][y] == '\0' || map[x][y] == ' ')
	{
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
		return (print_error(BADMAP));
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	}
	else if (map[x][y] == 's' || map[x][y] == 'd')
		return (0);
	else if (map[x][y] != '1')
	{
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
		if (map[x][y] == '0')
			map[x][y] = 's';
		if (map[x][y] == 'D')
			map[x][y] = 'd';
		return(flood_fill(map, x, y));
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	}
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	return (0);
}

static int	flood_fill(char **map, int x, int y)
{
	if (flood_fill_helper(map, x, y + 1))
		return (1);
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (flood_fill_helper(map, x, y - 1))
		return (1);
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (flood_fill_helper(map, x + 1, y))
		return (1);
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (flood_fill_helper(map,  x - 1, y))
		return (1);
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);
	return (0);
}

static int	*check_player(char **map, int *player_pos)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	// printf(G"DEBUG: CHECKING PLAYER"RESET" %s %d\n", __FILE__, __LINE__);
	while (map[y][x] != '\0')
	{
		while (map[y][x] != '\0')
		{
			// printf("DEBUG %s %d %c\n", __FILE__, __LINE__, map[y][x]);
			if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E' ||
				map[y][x] == 'S')
			{
				// printf("DEBUG %s %d\n", __FILE__, __LINE__);
				if (player_pos[0] != -1)
				{
					// printf("DEBUG %s %d\n", __FILE__, __LINE__);
					print_error(MULTIPLE_PLAYERS);
					return (NULL);
				}
				else
				{
					// printf("DEBUG %s %d\n", __FILE__, __LINE__);
					player_pos[0] = y;
					player_pos[1] = x;
				}
			}
			// printf("DEBUG %s %d\n", __FILE__, __LINE__);
			x++;
		}
		// printf("DEBUG %s %d\n", __FILE__, __LINE__);
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
