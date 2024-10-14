#ifndef DRAW_H
#define DRAW_H

#include <stdlib.h>
#include "mlx.h"

# define WIN_WIDTH 1400
# define WIN_HEIGHT 900
# define GRAY	0x808080
# define RED	0xFF0000
# define BLUE	0x87CEEB
# define GREEN	0x228B22

/*** player ***/
# define P_ANGLE_DEFAULT 6.28319
# define P_ROTATE_SPEED 6
# define P_MOUSE_SENSITIVITY 0.008
# define P_MOVE_SPEED 15
# define P_START_POSITION 5.0

/*** game ***/
# define FOV 1.0472
# define PI 3.1415926
# define RAY_SPEED 0.01
# define FPS 90

/*** keycodes ***/
# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct	s_img
{
	void	*data;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_text
{
	int		width;
	int		height;
	t_img	img;
}	t_text;


#endif