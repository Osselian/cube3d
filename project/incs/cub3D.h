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
    t_point start;
    t_point end;
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
	double	distance;
	double	texture_line;
	char	orientation;
}	t_wallhit;

typedef struct s_vector
{
	t_point	norm;
	t_point	val;
	double	len;
}	t_vector;

typedef struct s_fov
{
	t_point	start;
	t_point	end;
	double	width;
	double	iter_x;
	double	iter_y;
}	t_fov;

typedef struct s_player
{
	int			loc_x;
	int			loc_y;
	t_point		location;
	t_vector	dir;
	t_fov		fov;
}	t_player;

typedef struct s_calc
{
	bool	is_vert;
	double	len_delta;
	double	ray_hit_len;
	double	proj_loc_val;
	double	hit_dir_loc_val;
	double	dir_val;
	double	wall_face_dir;
	char	orients[2];
	double	target_norm_val;
}	t_calc;

typedef struct	s_ray
{
	double	x;
	double	y;
	double	len;
}	t_ray;

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
//player
void    init_player(t_player *player, int x, int y);
void    set_direction(t_vector *dir, char dir_key, int len, t_player player);
void    set_fov(t_vector *dir, t_fov *fov, int screen_width, double fov_width);
//raycast
double	delta_len(int index, t_point ray);
double	find_wall(t_calc *calc_data, t_point loc, char **map);
t_grid  *get_grid(char **map); //возможно, не понадобиться
int		get_line_inds(int *indexes, t_point location, t_point dir);
double  get_vectors_cos_angle(
			double proj_x, double proj_y, double raydir_x, double raydir_y);
double	ray_hit_len(int *line_inds, int index, t_player *player, t_point ray);
int		raycast(t_player *player, t_wallhit *hits, int scr_width, char **map);
//utils
bool	ft_isspace(const char a);
int		print_error(char *mes);
void	*safe_malloc(size_t str);

#endif