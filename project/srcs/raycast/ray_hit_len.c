#include "../../incs/cub3D.h"

double  get_cos_angle_vectors(
    double proj_x, double proj_y, double raydir_x, double raydir_y)
{
    double scalar;
    double abs_raydir;
    double abs_proj_vert;
    double cos_angle;

    scalar = proj_x * raydir_x + proj_y * raydir_y;
    abs_raydir = sqrt(pow(raydir_x, 2) + pow(raydir_y, 2));
    abs_proj_vert = sqrt(pow(proj_x, 2) + pow(proj_y, 2));
    cos_angle = scalar / abs_raydir / abs_proj_vert;
    return (cos_angle);
}

double ray_hit_len(int *line_inds, int index, t_player *player, t_point *ray)
{
    double proj_x;
    double proj_y;
    double proj_len;
    double cos_angle;

    if (index)
    {
        proj_x = line_inds[index] - player->location->x;
        proj_y = 0;
        proj_len = fabs(proj_x);
    }
    else
    {
        proj_x = 0;
        proj_y = line_inds[index] - player->location->y;
        proj_len = fabs(proj_y);
    }
    cos_angle = get_cos_angle_vectors(proj_x, proj_y, ray->x, ray->y);
    return (proj_len / cos_angle);
}