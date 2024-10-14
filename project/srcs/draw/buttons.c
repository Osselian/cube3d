#include "cub3D.h"
#include <sys/time.h>

static t_point	get_new_pos(const t_player *p, int keysym, double delta, double ang);
static t_point	calc_new_pos(double dir, double factor);

double get_current_time() 
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec + (time.tv_usec / 1000000.0));
}

double	get_delta_time()
{
	static double	prev_time = 0;
	double			delta;
	double			cur_time;

	cur_time = get_current_time();
	if (prev_time == 0)
        prev_time = cur_time;
	delta = cur_time - prev_time;
	if (delta > 1.0 / FPS)
		delta = 1.0 / FPS;
	prev_time = cur_time;
	return (delta);
}

int	exit_game(t_data *data)
{
	//free_game_data(data);
	exit(0);
}

int	buttons(int keysym, t_data *g)
{
	double	delta;
	double	ang = 0;
	t_point	new_pos;
	t_player *p;

	if (keysym < 0 || !g)
		return (1);
	delta = get_delta_time();
	p = &g->p;
	ft_memset(&new_pos, 0, sizeof(t_point));
	if (keysym == KEY_ESC)
		exit_game(g);
	else if (keysym == KEY_ARROW_LEFT)
		ang += P_ROTATE_SPEED * delta;
	else if (keysym == KEY_ARROW_RIGHT)
		ang -= P_ROTATE_SPEED * delta;
	else
		new_pos = get_new_pos(p, keysym, delta, ang);
	if (g->m->map[(int)new_pos.x][(int)new_pos.y] != '1')
		p->location = new_pos;
	if (ang < 0)
		ang += 2 * PI;
	if (ang >= 2 * PI)
		ang -= 2 * PI;
	draw_frame(g->w, &g->win_mng, &g->main_img, &g->wall);
	return (0);
}

static t_point	get_new_pos(const t_player *p, int keysym, double delta, double ang)
{
	t_point	new_pos;
	double	factor;

	factor = P_MOVE_SPEED * delta;
	ft_memset(&new_pos, 0, sizeof(t_point));
	if (keysym == KEY_W)
		new_pos = pos_sum(p->location, calc_new_pos(ang, factor));
	else if (keysym == KEY_D)
		new_pos = pos_sub(p->location, calc_new_pos(ang + PI / 2, factor));
	else if (keysym == KEY_S)
		new_pos = (pos_sub(p->location, calc_new_pos(ang, factor)));
	else if (keysym == KEY_A)
		new_pos = (pos_sum(p->location, calc_new_pos(ang + PI / 2, factor)));
	return(new_pos);	
}

static t_point	calc_new_pos(double dir, double factor)
{
	t_point	new_pos;

	new_pos.x = sin(dir) * factor;
	new_pos.y = cos(dir) * factor;
	return (new_pos);
}
