#include "../incs/cub3D.h"

int main(int argc, char **argv)
{
    t_data  *game;
    t_meta  *metadata;

    /* закомментил из-за SEGFAULT */
    if (argc < 2)
       return (print_error("No .cub file provided!\n"));

    metadata = meta_init(argv);
    if (!metadata)
         return (1);  
    printf("AFTER META INIT");
    print_metadata(metadata);
    // char *map[] = 
    // {
    //     "11111111111",
    //     "10000100001",
    //     "10000000001",
    //     "11000000011",
    //     "10000000001",
    //     "10000100001",
    //     "11111111111",
    //     NULL
    // };
    // metadata.map = map;
    game = game_init(metadata);
    if (!game)
        return (1);
	hooks_init(&game->win_mng, game);
    draw_frame(game);
  	mlx_loop(game->win_mng.mlx);
	mlx_loop_hook(game->win_mng.mlx, on_key_pressed, game);
    free_meta(metadata);
    free_data(game);
    return (0);
}