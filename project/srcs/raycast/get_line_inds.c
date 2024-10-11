#include "../../incs/cub3D.h"

int    get_line_inds(int *indexes, t_point location, t_point dir)
{
    int loc_cell_x;
    int loc_cell_y;

    loc_cell_x = location.x / 1;
    loc_cell_y = location.y / 1;
    if (dir.x == 0 && dir.y == 0)
        return (0);
    if (dir.x == 0)
        indexes[1] = -1;
    if (dir.y == 0)
        indexes[0] = -1;
    if (dir.x > 0)
        indexes[1] = loc_cell_x + 1;
    else if (dir.x < 0)
        indexes[1] = loc_cell_x;
    if (dir.y > 0)
        indexes[0] = loc_cell_y;
    else if (dir.y < 0)
        indexes[0] = loc_cell_y - 1;
    return (1);
}