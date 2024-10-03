#include "../../incs/cub3D.h"

void    set_fov_bounds(t_dir *dir, t_fov *fov)
{
    double start_x;
    double start_y;
    double end_x;
    double end_y;

    start_x = dir->norm->y * -1;
    start_y = dir->norm->x;
    end_x = dir->norm->y;
    end_y = dir->norm->x * -1;
    fov->fov_start->x = dir->val->x + (start_x * fov->fov_width);
    fov->fov_start->y = dir->val->y + (start_y * fov->fov_width);
    fov->fov_end->x = dir->val->x + (end_x * fov->fov_width);
    fov->fov_end->y = dir->val->y + (end_y * fov->fov_width);
}

t_point **get_ray_bounds(t_player *player)
{
    t_point **bounds;

    bounds = (t_point **)malloc(sizeof(t_point *) * 2);
    if (!bounds) 
        return (NULL);
    bounds[0] = (t_point *)malloc(sizeof(t_point )); 
    bounds[1] = (t_point *)malloc(sizeof(t_point )); 
    if (!bounds[0] || !bounds[1])
        return (free_arr((void **)bounds, free));
    // bounds[0]->x = player->fov->dir->x * player->fov->dir_len +
}