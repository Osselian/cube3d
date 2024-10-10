#include "../../incs/cub3D.h"

static bool is_wall(char **map, int *init_loc, double dir, int is_vert)
{
    int res[2];

    if (is_vert)
    {
        res[1] = init_loc[1];
        if (dir > 0)
            res[0] = init_loc[0] + 1;
        else 
            res[0] = init_loc[0] - 1;
    }
    else
    {
        res[0] = init_loc[0];
        if (dir > 0)
            res[1] = init_loc[1] + 1;
        else 
            res[1] = init_loc[1] - 1;
    }
    return (map[res[1]][res[0]] == '1');
}

static void    set_init_loc(
    int i, int *init_loc, t_player *player, double cell_val)
{
    if (i == 0)
    {
        init_loc[0] = player->loc_x;
        init_loc[1] = (int)cell_val;
    }
    else
    {
        init_loc[0] = (int)cell_val;
        init_loc[1] = player->loc_y;
    }
}

double    find_wall(
    t_calc *calc_data, t_vector *ray, t_player *player, char **map)
{
    double  hit_val_on_line;
    int     init_loc[2];
    double  cell_val;
    t_calc  target_data;
    int     i;

    if (calc_data[0].ray_hit_len <= calc_data[1].ray_hit_len)
        i = 0;
    else
        i = 1;
    target_data = calc_data[i];
    hit_val_on_line = target_data.target_norm_val * target_data.ray_hit_len;
    modf(hit_val_on_line, &cell_val);
    set_init_loc(i, init_loc, player, cell_val);
    if (is_wall(map, init_loc, ray->val.x, 1))
        return (hit_val_on_line);
    target_data.ray_hit_len += target_data.len_delta;
    return (find_wall(calc_data, ray, player, map));
}
