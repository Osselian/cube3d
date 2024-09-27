/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:48:13 by osse              #+#    #+#             */
/*   Updated: 2024/09/27 10:02:11 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
//#include "mlx_int.h"

int main(int argc, char **argv)
{
    void *mlx;
    void *mlx_win;

    (void)argc;
    (void)argv;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 600, "Hello, World!");
    mlx_loop(mlx);
    write(1, "Hello\n", 6);
    return (0);
}