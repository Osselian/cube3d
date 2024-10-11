#include "../../incs/cub3D.h"

static bool is_wall(char **map, int *init_loc, double dir, int is_hor)
{
    int res[2];

    int x = init_loc[0];
    int y = init_loc[1];
    if (!is_hor)
    {
        res[1] = init_loc[1] * -1;
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
        res[1] *= -1;
    }
    return (map[res[1]][res[0]] == '1');
}

static void    set_init_loc(
    int i, int *init_loc, t_point loc, double cell_val)
{
    if (i == 0)
    {
        init_loc[0] = loc.x;
        init_loc[1] = (int)cell_val;
    }
    else
    {
        init_loc[0] = (int)cell_val;
        init_loc[1] = loc.y;
    }
}

static double   get_val_on_line(t_calc calc_data)
{
    double  res;
    double  len;

    len = calc_data.target_norm_val * calc_data.ray_hit_len;
    res = calc_data.hit_dir_loc_val + len;
    return(res);
}

void    inc_loc(int is_hor, t_point *loc, double dir)
{
    if (!is_hor)
    {
        if (dir > 0)
            loc->x += 1;
        else 
            loc->x -= 1;
    }
    else
    {
        if (dir > 0)
            loc->y -= 1;
        else 
            loc->y += 1;
    }
}

double    find_wall(t_calc *calc_data, t_point loc, char **map)
{
    double  val_on_line;
    int     init_loc[2];
    double  cell_val;
    t_calc  *target;
    int     i;

    t_calc vert_data = calc_data[0];
    t_calc hor_data = calc_data[1];
    if (calc_data[0].ray_hit_len <= calc_data[1].ray_hit_len)
        i = 0;
    else
        i = 1;
    target = &calc_data[i];
    val_on_line = get_val_on_line(*target);
    modf(val_on_line, &cell_val);
    set_init_loc(i, init_loc, loc, cell_val);
    if (is_wall(map, init_loc, target->wall_face_dir, i))
        return (val_on_line);
    target->ray_hit_len += target->len_delta;
    inc_loc(i, &loc, target->wall_face_dir);
    return (find_wall(calc_data, loc, map));
}
