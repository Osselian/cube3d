#ifndef CUB3D
# define CUB3D

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
//#include "mlx_int.h"

typedef struct s_point{
    double x;
    double y; 
}   t_point;

typedef struct s_line{
    t_point *start;
    t_point *end;
}   t_line;

typedef struct s_grid
{
    t_line  **vert;
    t_line  **hor;
}   t_grid;

typedef struct s_txtr
{
	bool	is_txtr; //FALSE for color, TRUE for texture
	char	*txtr_val;
}	t_txtr;

typedef struct s_meta
{
	t_txtr	*no_txtr;
	t_txtr	*so_txtr;
	t_txtr	*we_txtr;
	t_txtr	*ea_txtr;
	t_txtr	*fl_txtr;
	t_txtr	*ce_txtr;
	char	**map;
}	t_meta;

int     getstrlen(char *str);

t_grid  *get_grid(char **map);

//free.c
void    free_grid(t_grid *grid);
void    free_line(void *line);
void    *free_arr(void **arr, void (*free_func)(void *));

void    print_grid_lines(t_grid *grid);

int		print_error(char *mes);
int		parse_input(char **argv, t_meta *metadata);
int		meta_init(char **argv, t_meta *metadata);
void	*safe_malloc(size_t str);

#endif