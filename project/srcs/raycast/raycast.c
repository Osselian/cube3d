#include "../../incs/cub3D.h"

static t_vector    set_ray(
    double raypoint_x, double raypoint_y, t_player *player)
{
    t_vector    ray;

    // ray = (t_vector *)safe_malloc(sizeof(t_vector));
    // val = (t_vector *)safe_malloc(sizeof(t_vector));
    // norm = (t_vector *)safe_malloc(sizeof(t_vector));
    // if (!ray || !val || !norm)
    //     return (NULL);
    ray.val.x = raypoint_x - player->location.x;
    ray.val.y = raypoint_y - player->location.y;
    return (ray);
}

static void    update_ray(t_vector *ray)
{
    ray->len = sqrt(pow(ray->val.x, 2) + pow(ray->val.y, 2));
    ray->norm.x = ray->val.x / ray->len;
    ray->norm.y = ray->val.y / ray->len;
}

static void    fill_calc_data(
    t_calc *calc_data, t_vector *ray, t_player *player, int *line_inds)
{
    calc_data[0].ray_hit_len = ray_hit_len(line_inds, 1, player, ray->val);
    calc_data[1].ray_hit_len = ray_hit_len(line_inds, 0, player, ray->val);
    calc_data[0].len_delta = delta_len(1, ray->val);
    calc_data[1].len_delta = delta_len(0, ray->val);

    calc_data[0].is_vert = 1;
    calc_data[0].wall_face_dir = ray->val.x;
    calc_data[0].orients[0] = 'e';
    calc_data[0].orients[1] = 'w';
    calc_data[0].dir_val = ray->val.y;
    calc_data[0].proj_loc_val = player->location.x;
    calc_data[0].hit_dir_loc_val = player->location.y;
    calc_data[0].target_norm_val = ray->norm.y; 

    calc_data[1].is_vert = 0;
    calc_data[1].wall_face_dir = ray->val.y;
    calc_data[1].orients[0] = 's';
    calc_data[1].orients[1] = 'n';
    calc_data[1].dir_val = ray->val.x;
    calc_data[1].proj_loc_val = player->location.y;
    calc_data[1].hit_dir_loc_val = player->location.x;
    calc_data[1].target_norm_val = ray->norm.x; 
}


static void    fill_wallhit(
    t_wallhit *hit, t_calc *calc_data, double hit_on_line, int screen_width)
{
    double  rel_hit;
    double  integral_part;

    hit->distance = calc_data->ray_hit_len;
    if (calc_data->wall_face_dir < 0)
        hit->orientation = calc_data->orients[0];
    else
        hit->orientation = calc_data->orients[1];
    rel_hit = modf(hit_on_line, &integral_part);
    hit->texture_line = fabs(screen_width * rel_hit);
}

int raycast(t_player *player, t_wallhit *hits, int scr_width, char **map)
{
    int          i;
    t_vector    ray;
    t_calc      calc_data[2];
    int         line_inds[2];
    double      hit_val_on_line;

    ray = set_ray(player->fov.start.x, player->fov.start.y, player);
    // if (!ray)
    //     return (0);
    i = 0;
    while (i < scr_width)
    {
        update_ray(&ray);
        if (!get_line_inds(line_inds, player->location, ray.val))
            return (0);
        fill_calc_data(calc_data, &ray, player, line_inds);
        hit_val_on_line = find_wall(calc_data, player->location, map);
        fill_wallhit(&(hits[i]), calc_data, hit_val_on_line, scr_width);
        ray.val.x += player->fov.iter_x;
        ray.val.y += player->fov.iter_y;
        i++;
    }
    return (1);
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
