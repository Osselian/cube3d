// #include "../../incs/cub3D.h"

// static int	flood_fill(char **map, int *player_pos);

// static int	flood_fill_helper(char **map, int *player_pos)
// {

// 	if (map[player_pos[0]][player_pos[1]] == '\0' || map[player_pos[0]][player_pos[1]] == ' ')
// 		return (1);
// 	else if (map[player_pos[0]][player_pos[1]] != '1')
// 		return(flood_fill(map, player_pos));
// 	return (0);
// }

// static int	flood_fill(char **map, int *player_pos)
// {
// 	if (flood_fill_helper(map, &map[player_pos[0]][player_pos[1] + 1]))
// 		return (1);
// 	if (flood_fill_helper(map, &map[player_pos[0]][player_pos[1] - 1]))
// 		return (1);
// 	if (flood_fill_helper(map, &map[player_pos[0] + 1][player_pos[1]]))
// 		return (1);
// 	if (flood_fill_helper(map, &map[player_pos[0] - 1][player_pos[1]]))
// 		return (1);
// 	return (0);
// }

// static int	*check_player(char **map, int *player_pos)
// {
// 	int	x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 	while (map[y][x] != '\0')
// 	{
// 		printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 		while (map[y][x])
// 		{
// 			printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 			if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'E' ||
// 				map[y][x] == 'S')
// 			{
// 				printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 				if (player_pos)
// 				{
// 					printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 					print_error(MULTIPLE_PLAYERS);
// 					return (NULL);
// 				}
// 				else
// 				{
// 					printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 					player_pos[0] = y;
// 					player_pos[1] = x;
// 				}
// 			}
// 			printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 			x++;
// 		}
// 		printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 		y++;
// 		x = 0;
// 	}
// 	printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 	return (player_pos);
// }

// int	check_map(char **map)
// {
// 	int	player_pos[2];

// 	printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 	if (check_player(map, player_pos) == NULL)
// 		return (1);
// 	printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 	if (flood_fill(map, player_pos))
// 		return (1);
// 	printf("DEBUG %s %d\n", __FILE__, __LINE__);
// 	return (0);
// }
