#include "cub3D.h"

// int get_options(char *path)
// {
//     // int fd;

//     // fd = open(path, );
//     return (0);
// }

int main(int argc, char **argv)
{
    // void *mlx;
    // void *mlx_win;
    t_grid *grid; 
  t_meta  *metadata;
    t_player player;
    t_wallhit   *wallhits;

    if (argc < 2)
        return (print_error("No .cub file provided!\n"));

    if (!meta_init(argv, metadata))
        return (1);  
    
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

    // grid = get_grid(map);
    // print_grid_lines(grid);

    int screen_width = 800;
    init_player(&player, 6, 3);
    wallhits = (t_wallhit *)safe_malloc(sizeof(t_wallhit) * (screen_width + 1));
    set_direction(&(player.dir), 'N', 3);
    set_fov(&(player.dir), &(player.fov), screen_width, 5);
    int res = raycast(&player, wallhits, screen_width, map);

    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 800, 600, "Hello, World!");
    // mlx_loop(mlx);

    write(1, "Hello\n", 6);
    return (0);
}