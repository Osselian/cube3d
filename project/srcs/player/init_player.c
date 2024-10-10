#include "../../incs/cub3D.h"

void    init_player(t_player *player, int x, int y)
{
   player->loc_x = x;
   player->loc_y = y; 
   player->location.x = x + 0.5;
   player->location.y = y + 0.5;
}