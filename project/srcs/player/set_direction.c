#include "../../incs/cub3D.h"

void    set_direction(t_player *player, char dir_key, int len)
{
    if (dir_key == 'N')
    {
       player->dir.norm.x = 0;
       player->dir.norm.y = 1;
    }
    else if (dir_key == 'S')
    {
        player->dir.norm.x = 0;
        player->dir.norm.y = -1;
    }
    else if (dir_key == 'E')
    {
       player->dir.norm.x = 1;
       player->dir.norm.y = 0;
    }
    else if (dir_key == 'W')
    {
       player->dir.norm.x = -1;
       player->dir.norm.y = 0;
    }
    player->dir.len = len;
    update_direction(player);
}
