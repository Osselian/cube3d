#include "../incs/cub3D.h"

// int get_options(char *path)
// {
//     // int fd;

//     // fd = open(path, );
//     return (0);
// }

int main(int argc, char **argv)
{
    t_grid *grid; 
    t_meta  *metadata;
    t_player player;
    t_data  game;

    //if (argc < 2)
    //   return (print_error("No .cub file provided!\n"));

    char *map[] = 
    {
        "11111111111",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "10000000001",
        "11111111111",
        NULL
    };

    init_player(&game.p, 6, -3);
    game.w = (t_wallhit *)safe_malloc(sizeof(t_wallhit) * (WIN_WIDTH + 1));
    set_direction(&(player.dir), 'N', 3, player);
    set_fov(&(player.dir), &(player.fov), WIN_WIDTH, 5);
    int res = raycast(&player, game.w, WIN_WIDTH, map);

    /* start init main data */
    game.win_mng = new_mlx();
	game.main_img = new_img(game.win_mng.mlx, WIN_WIDTH, WIN_HEIGHT);
    game.m = metadata;
    game.wall.img.data = mlx_xpm_file_to_image(game.win_mng.mlx,
                                                  "data/textures/greystone.xpm",
                                                  &game.wall.width,
                                                  &game.wall.height);
    game.wall.img.data_addr = mlx_get_data_addr(game.wall.img.data,
                                                    &game.wall.img.bits_per_pixel,
                                                    &game.wall.img.size_line,
                                                    &game.wall.img.endian);
    /* end init main data */

    draw_frame(game.w, &game.win_mng, &game.main_img, &game.wall);
	hooks_init(&game.win_mng, &game);
	mlx_loop(game.win_mng.mlx);
	mlx_loop_hook(game.win_mng.mlx, buttons, &game);
    return (0);
}