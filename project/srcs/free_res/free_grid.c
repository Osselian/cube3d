#include "../incs/cub3D.h"

void    free_grid(t_grid *grid)
{
    if (grid->vert)
        free_arr((void **)grid->vert, free_line);
    if (grid->hor)
        free_arr((void **)grid->hor, free_line);
    free(grid);
}