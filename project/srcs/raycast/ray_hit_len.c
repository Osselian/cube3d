#include "../../incs/cub3D.h"

double ray_hit_len(int *line_inds, int index, t_player *player, t_point ray)
{
    double proj_x;
    double proj_y;
    double proj_len;
    double cos_angle;

    if (index)
    {
        int ind = line_inds[index];
        proj_x = line_inds[index] - player->location.x;
        proj_y = 0;
        proj_len = fabs(proj_x);
    }
    else
    {
        proj_x = 0;
        proj_y = line_inds[index] - player->location.y;
        proj_len = fabs(proj_y);
    }
    cos_angle = get_vectors_cos_angle(proj_x, proj_y, ray.x, ray.y);
    return (proj_len / cos_angle);
}
