#include "../incs/cub3D.h"

int get_options(char *path)
{
    // int fd;

    // fd = open(path, );
    return (0);
}

int main(int argc, char **argv)
{
    void    *mlx;
    void    *mlx_win;
    t_meta  *metadata;

    if (argc < 2)
        return (print_error("No .cub file provided!\n"));
    if (!meta_init(argv, metadata))
        return (1);  
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 800, 600, "Hello, World!");
    // mlx_loop(mlx);
    write(1, "Hello\n", 6);
    return (0);
}