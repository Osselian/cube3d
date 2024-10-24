#include "../../incs/cub3D.h"

void    set_direction(t_vector *dir, char dir_key, int len, t_player player)
{
    if (dir_key == 'N')
    {
        dir->norm.x = 0;
        dir->norm.y = 1;
    }
    else if (dir_key == 'S')
    {
        dir->norm.x = 0;
        dir->norm.y = -1;
    }
    else if (dir_key == 'E')
    {
        dir->norm.x = 1;
        dir->norm.y = 0;
    }
    else if (dir_key == 'W')
    {
        dir->norm.x = -1;
        dir->norm.y = 0;
    }
    dir->len = len;
    dir->val.x = player.location.x + dir->norm.x * len;
    dir->val.y = player.location.y + dir->norm.y * len;
}
