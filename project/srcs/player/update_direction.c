#include "../../incs/cub3D.h"

void    update_direction( t_player *p) 
{
    p->dir.val.x = p->location.x + p->dir.norm.x * p->dir.len;
    p->dir.val.y = p->location.y + p->dir.norm.y * p->dir.len;
}