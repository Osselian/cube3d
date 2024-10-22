#include "../../incs/cub3D.h"

char *text[] =
{
    "./data/textures/greystone.xpm", 
    "./data/textures/redbrick.xpm",
    "./data/textures/bluestone.xpm",
    "./data/textures/colorstone.xpm",
    NULL
};

t_data *new_data(t_meta *metadata)
{
    t_data *game;
    int i = -1;

    game = (t_data *)safe_malloc(sizeof(t_data));
    if (!game)
        return (NULL);
    game->wh = (t_wallhit *)safe_malloc(sizeof(t_wallhit) * (WIN_WIDTH + 1));
    if (!game->wh)
        return (free_data(game));
    init_player(&game->player, 6, -3);
    set_direction(&game->player.dir, 'W', 3, game->player);
    set_fov(&game->player.dir, &game->player.fov, WIN_WIDTH, 5);
    game->win_mng = new_mlx();
	game->main_img = new_img(game->win_mng.mlx, WIN_WIDTH, WIN_HEIGHT);
    game->wall = malloc(sizeof(t_text) * 4);
    game->m_data = metadata;
    while (++i < 4)
    {
        game->wall[i].img.data = mlx_xpm_file_to_image(game->win_mng.mlx,
                                                  text[i],
                                                  &game->wall[i].width,
                                                  &game->wall[i].height);
        game->wall[i].img.data_addr = mlx_get_data_addr(game->wall[i].img.data,
                                                    &game->wall[i].img.bits_per_pixel,
                                                    &game->wall[i].img.size_line,
                                                    &game->wall[i].img.endian);
    }
    raycast(&game->player, game->wh, WIN_WIDTH, game->m_data->map);
    return (game);
}

t_data  *free_data(t_data *g)
{
    free(g->wh);
    /* free_meta(g->m_data) */ // TODO
    free_mlx(&g->win_mng, g->main_img.data, g->wall[0].img.data);
    free(g);
    return (NULL);
}