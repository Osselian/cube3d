#ifndef CUB3D
# define CUB3D

# define INCORRECT_COORDS		"Incorrect textures in .cub - check coords\n"
# define INCORRECT_FORMAT		"Incorrect .cub format - leave empty line before FLOOR texture\n"
# define INCORRECT_FILE			"Incorrect file type. Shall be .cub\n"
# define INCORRECT_COLOR		"Incorrect color input. Check is it a correct RGB format\n"
# define NO_FILE				"File passed as map or texture doesn't exist\n"
# define INCORRECT_MAP_SYMBOL	"Incorrect symbol passed in map scratch. Shall be in [0, 1, W, E, S, N, SPACE]\n"
# define MULTIPLE_PLAYERS		"There can not be more than 1 player in the Game, check input file!\n"
# define ZERO_PLAYERS			"There can't be zero players, check input file!\n"
# define BADMAP					"Incorrect map, shall be framed with walls!\n"
# define BAD_TXTR_EXT			"Incorrect texture extention, shall be .png\n"
# define LONGMAP				"Map is too big, maximum is MAXINTxMAXINT!\n"

# define RESET	"\033[0m"
# define RED	"\033[1;31m"
# define BLUE	"\033[1;34m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
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

typedef union u_color
{
  int i;
  char c[4];
}  t_color;

/*
MAP documentetion
	- N, S, W, E: изначальная координата игрока
	- 1: стена, которую игрок никода не увидит
	- 0: пустое пространство, которое игрок никода не увидит
	- s: пустое пространство
	- D: дверь, которую игрок никогда не увидит
	- d:дверь
*/
typedef struct s_meta
{
	char	*no_txtr;
	char	*so_txtr;
	char	*we_txtr;
	char	*ea_txtr;
	t_color	*fl_txtr;
	t_color	*ce_txtr;
	char	**map;
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
	double	val_on_line;
}	t_calc;

typedef struct	s_ray
{
	double	x;
	double	y;
	double	len;
}	t_ray;

//debug.c
void    print_grid_lines(t_grid *grid);
void    print_wallhit(t_wallhit *wallhit, int screen_width);
void    print_metadata(t_meta  *meta);
//free_res
void    free_grid(t_grid *grid);
void    free_line(void *line);
void    *free_arr(void **arr, void (*free_func)(void *));
void	free_meta(t_meta *meta);
//parser
int		meta_init(char **argv, t_meta *metadata);
int		parse_dir(t_meta *meta, char *ln, long ln_nbr);
int 	fill_wall(char *ln, int ln_nbr, t_meta *meta);
int		parser(char **argv, t_meta *metadata);
//player
void    init_player(t_player *player, int x, int y);
void    set_direction(t_vector *dir, char dir_key, int len, t_player player);
void    set_fov(t_vector *dir, t_fov *fov, int screen_width, double fov_width);
//raycast
double	delta_len(int index, t_point ray);
t_calc	find_wall(t_calc *calc_data, t_point loc, char **map);
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
void	ft_straddchar(char **str, char c);

bool	check_color(char *ln);
int		parse_map(t_meta *meta, char *ln);
int		ft_addline(char **arr, char *ln);
int		check_map(char **map);

#endif
