#include "../incs/cub3D.h"

void    free_line(void *obj)
{
    t_line  *line;

    line = (t_line *)obj;
    if (line->start)
        free(line->start);
    if (line->end)
        free(line->end);
    free(line);
}