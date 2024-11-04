#include "../../incs/cub3D.h"

bool    is_wall2(int is_hor, t_calc calc_data, char **map)
{
    double  y;
    double  x;

    if (is_hor ) 
    {
        y = round(calc_data.ray_hit.val.y);
        modf(calc_data.ray_hit.val.x, &x);
        if (calc_data.ray_hit.norm.y > 0)
            y++;
    }
    else if (!is_hor)
    {
        x = round(calc_data.ray_hit.val.x);
        modf(calc_data.ray_hit.val.y, &y);
        if (calc_data.ray_hit.norm.x < 0)
            x--;
    }
    return (map[(int)fabs(y)][(int)x] == '1');
}

t_calc    find_wall(t_calc *calc_data, t_point loc, char **map)
{
    t_calc  *target;
    int     i;

    if (calc_data[0].ray_hit.len <= calc_data[1].ray_hit.len)
        i = 0;
    else
        i = 1;
    target = &calc_data[i];
    if (is_wall2(i, *target, map))
        return (*target);
    target->ray_hit.len += target->len_delta;
    target->ray_hit.val.x = 
        loc.x + target->ray_hit.norm.x * target->ray_hit.len;
    target->ray_hit.val.y = 
        loc.y + target->ray_hit.norm.y * target->ray_hit.len;
    return (find_wall(calc_data, loc, map));
}
