/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osse <osse@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:48:13 by osse              #+#    #+#             */
/*   Updated: 2024/09/27 11:30:47 by osse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3D.h"

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

    if (argc < 2)
        return (print_error("No .cub file provided!\n"));

    (void)argv;
    
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

    grid = get_grid(map);
    print_grid_lines(grid);
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 800, 600, "Hello, World!");
    // mlx_loop(mlx);

    write(1, "Hello\n", 6);
    return (0);
}