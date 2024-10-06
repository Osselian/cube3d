#include "../../incs/cub3D.h"

t_vector    *set_ray(double raypoint_x, double raypoint_y, t_player *player)
{
    t_vector    *ray;
    t_point     *val;
    t_point     *norm;

    ray = (t_vector *)safe_malloc(sizeof(t_vector));
    val = (t_vector *)save_malloc(sizeof(t_vector));
    norm = (t_vector *)save_malloc(sizeof(t_vector));
    if (!ray || !val || !norm)
        return (NULL);
    val->x = raypoint_x - player->location->x;
    val->y = raypoint_y - player->location->y;
    ray->val = val;
    ray->norm = norm;
    return (ray);
}

void    update_ray(t_vector *ray)
{
    ray->len = sqrt(pow(ray->val->x, 2) + pow(ray->val->y, 2));
    ray->norm->x = ray->val->x / ray->len;
    ray->norm->y = ray->val->y / ray->len;
}

int    *get_line_inds(t_point *location, t_point *dir)
{
    int loc_cell_x;
    int loc_cell_y;
    int indexes[2];

    loc_cell_x = location->x / 1;
    loc_cell_y = location->y / 1;
    if (dir->x == 0 && dir->y == 0)
        return (NULL);
    if (dir->x == 0)
        indexes[1] = -1;
    if (dir->y == 0)
        indexes[0] = -1;
    if (dir->x > 0)
        indexes[1] = loc_cell_x + 1;
    else if (dir->x < 0)
        indexes[1] = loc_cell_x - 1;
    if (dir->y > 0)
        indexes[0] = loc_cell_y + 1;
    else if (dir->y < 0)
        indexes[0] = loc_cell_y - 1;
    return (indexes);
}

void    fill_calc_data(t_calc **calc_data, t_vector *ray, t_player *player)
{
    calc_data[0]->is_vert = 1;
    calc_data[0]->wall_face_dir = ray->val->x;
    calc_data[0]->orients[0] = 'e';
    calc_data[0]->orients[1] = 'w';
    calc_data[0]->dir_val = ray->val->y;
    calc_data[0]->proj_loc_val = player->location->x;
    calc_data[0]->hit_dir_loc_val = player->location->y;
    calc_data[0]->target_norm_val = ray->norm->x; 

    calc_data[1]->is_vert = 0;
    calc_data[1]->wall_face_dir = ray->val->y;
    calc_data[1]->orients[0] = 's';
    calc_data[1]->orients[1] = 'n';
    calc_data[1]->dir_val = ray->val->x;
    calc_data[1]->proj_loc_val = player->location->y;
    calc_data[1]->hit_dir_loc_val = player->location->x;
    calc_data[1]->target_norm_val = ray->norm->y; 
}


void    fill_wallhit(
    t_wallhit *hit, t_calc *calc_data, double hit_on_line, int screen_width)
{
    double rel_hit;

    hit->distance = calc_data->ray_hit_len;
    if (calc_data->wall_face_dir < 0)
        hit->orientation = calc_data->orients[0];
    else
        hit->orientation = calc_data->orients[1];
    rel_hit = modf(hit_on_line, NULL);
    hit->texture_line = screen_width * rel_hit;
}

t_point **raycast(
    t_player *player, t_wallhit *hits, int screen_width, char **map)
{
    int          i;
    t_vector    *ray;
    t_calc      calc_data[2];
    int         *line_inds;
    double      hit_val_on_line;

    ray = set_ray(player->fov->start->x, player->fov->start->y, player);
    if (!ray)
        return (NULL);
    i = 0;
    while (i < screen_width)
    {
        update_ray(ray);
        line_inds = get_line_inds(player->location, ray);
        calc_data[0].ray_hit_len = ray_hit_len(line_inds, 1, player, ray);
        calc_data[1].ray_hit_len = ray_hit_len(line_inds, 0, player, ray);
        //сделать расчет len_delta
        fill_calc_data(&calc_data, ray, player);
        hit_val_on_line = find_wall(&calc_data, ray, player, map);
        fill_wallhit(&(hits[i]), calc_data, hit_val_on_line, screen_width);
        ray->val->x += player->fov->iter_x;
        ray->val->y += player->fov->iter_y;
        i++;
    }
}

// double  cathetus_len(double hip_len, double cathetus_len)
// {
//     return (sqrt(pow(hip_len, 2) - pow(cathetus_len, 2)));
// }

// double    get_hit_val_on_line(t_calc *calc_data)
// {   
//     double loc_proj_len;
//     double ray_proj_len;
//     double hit_point_on_line;

//     loc_proj_len = fabs(calc_data->grid_line_ind - calc_data->proj_loc_val);
//     double ray_proj_len = cathetus_len(calc_data->ray_hit_len, loc_proj_len);
//     if (calc_data->dir_val > 0)
//         hit_point_on_line = calc_data->hit_dir_loc_val + ray_proj_len;
//     else
//         hit_point_on_line = calc_data->hit_dir_loc_val - ray_proj_len;
//     return (hit_point_on_line);
// }
