#ifndef CUB3D
# define CUB3D

# define INCORRECT_COORDS	"Incorrect textures in .cub - check coords\n"
# define INCORRECT_FORMAT	"Incorrect .cub format - leave empty line before FLOOR texture\n"
# define INCORRECT_FILE		"Incorrect file type. Shall be .cub\n"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
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
	bool	ok_flg;
}	t_meta;

typedef struct s_wallhit
{
	int		wx;
	int		wy;
	t_point	*hitpoint;
}	t_wallhit;

typedef struct s_dir
{
	t_point	*norm;
	t_point	*val;
	double	len;
}	t_dir;

typedef struct s_fov
{
	t_point	*fov_start;
	t_point	*fov_end;
	int		fov_width;
}	t_fov;

typedef struct s_player
{
	t_point	*location;
	t_dir	*dir;
	t_fov	*fov;
}	t_player;

//debug.c
void    print_grid_lines(t_grid *grid);
//free_res
void    free_grid(t_grid *grid);
void    free_line(void *line);
void    *free_arr(void **arr, void (*free_func)(void *));
//parser
int		meta_init(char **argv, t_meta *metadata);
int		parse_dir(t_meta *meta, char *ln, int ln_nbr);
int		parse_input(char **argv, t_meta *metadata);
//raycast
t_grid  *get_grid(char **map);
//utils
bool	ft_isspace(const char a);
int		print_error(char *mes);
void	*safe_malloc(size_t str);

#endif