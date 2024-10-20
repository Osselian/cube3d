#include "../../incs/cub3D.h"

t_data *new_data(t_meta *metadata)
{
    t_data *game;

    game = (t_data *)safe_malloc(sizeof(t_data));
    if (!game)
        return (NULL);
    game->wh = (t_wallhit *)safe_malloc(sizeof(t_wallhit) * (WIN_WIDTH + 1));
    if (!game->wh)
        return (free_data(game));
    init_player(&game->player, 6, -3);
    set_direction(&game->player.dir, 'W', 3, game->player);
    set_fov(&game->player.dir, &game->player.fov, WIN_WIDTH, 5);
    game->player.ang = atan2(game->player.dir.val.x, game->player.dir.val.y);
    game->win_mng = new_mlx();
	game->main_img = new_img(game->win_mng.mlx, WIN_WIDTH, WIN_HEIGHT);
    game->m_data = metadata;
    game->wall.img.data = mlx_xpm_file_to_image(game->win_mng.mlx,
                                                  "./data/textures/greystone.xpm",
                                                  &game->wall.width,
                                                  &game->wall.height);
    game->wall.img.data_addr = mlx_get_data_addr(game->wall.img.data,
                                                    &game->wall.img.bits_per_pixel,
                                                    &game->wall.img.size_line,
                                                    &game->wall.img.endian);
    raycast(&game->player, game->wh, WIN_WIDTH, game->m_data->map);
    return (game);
}

t_data  *free_data(t_data *g)
{
    free(g->wh);
    /* free_meta(g->m_data) */ // TODO
    free_mlx(&g->win_mng, g->main_img.data, g->wall.img.data);
    free(g);
    return (NULL);
}