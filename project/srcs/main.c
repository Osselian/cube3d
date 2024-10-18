#include "../incs/cub3D.h"

int main(int argc, char **argv)
{
    t_meta  metadata;
    t_data  *game;

    //if (argc < 2)
    //   return (print_error("No .cub file provided!\n"));
    (void)argc;
    (void)argv;
    char *map[] = 
    {
        "11111111111",
        "10000100001",
        "10000000001",
        "11000000011",
        "10000000001",
        "10000100001",
        "11111111111",
        NULL
    };
    metadata.map = map;
    game = new_data(&metadata);
    if (!game)
        return (1);
	hooks_init(&game->win_mng, game);
    draw_frame(game->wh, &game->win_mng, &game->main_img, &game->wall);
	mlx_loop(&game->win_mng.mlx);
	mlx_loop_hook(game->win_mng.mlx, buttons, game);
    return (0);
}