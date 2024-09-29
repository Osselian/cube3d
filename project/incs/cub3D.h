#ifndef CUB3D
# define CUB3D

# include <unistd.h>
# include "mlx.h"
# include <fcntl.h>
//#include "mlx_int.h"

typedef struct s_point{
    int x;
    int y; 
}   t_point;

typedef struct s_line{
    t_point start;
    t_point end;
}   t_line;

int print_error(char *mes);

int getstrlen(char *str);

#endif