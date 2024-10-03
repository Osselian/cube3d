#include "../../incs/cub3D.h"

void    set_fov_bounds(t_dir *dir, t_fov *fov)
{
    double start_x;
    double start_y;
    double end_x;
    double end_y;

    //implement new struct
    start_x = fov->dir->y * -1;
    start_y = fov->dir->x;
    end_x = fov->dir->y;
    end_y = fov->dir->x * -1;
    fov->fov_start->x = 
        (fov->dir->x * fov->dir_len) + (start_x * fov->fov_width);
    fov->fov_start->y = 
        (fov->dir->y * fov->dir_len) + (start_y * fov->fov_width);
    fov->fov_end->x = 
        (fov->dir->x * fov->dir_len) + (end_x * fov->fov_width);
    fov->fov_end->y = 
        (fov->dir->y * fov->dir_len) + (end_y * fov->fov_width);
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