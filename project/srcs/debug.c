#include "../incs/cub3D.h"

void    print_grid_lines(t_grid *grid)
{
    int i = 0;

    while (grid->vert[i])
    {
        printf("start x - %f, start y - %f\nend x - %f, end y - %f\n", 
            grid->vert[i]->start->x, grid->vert[i]->start->y, 
            grid->vert[i]->end->x, grid->vert[i]->end->y);
        i++;
    }
}