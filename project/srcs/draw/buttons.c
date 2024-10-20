#include "../../incs/cub3D.h"
#include <stdbool.h>

static t_point	get_new_pos(const t_player *p, int keysym, double delta, double ang);
static t_point	calc_new_pos(double dir, double factor);
static t_point	calc_direction( t_player *p);
static t_point	get_new_pos2(t_player *p, int keysym, double delta);
static bool		check_new_pos(char **map, t_point new_pos, t_vector dir);

int	exit_game(t_data *data)
{
	free_data(data);
	exit(0);
}

static t_point	calc_direction( t_player *p)
{
	t_point	new_pos;
	
    p->dir.val.x = p->location.x + p->dir.norm.x * p->dir.len;
    p->dir.val.y = p->location.y + p->dir.norm.y * p->dir.len;
    return (new_pos);
}

int	buttons(int keysym, t_data *g)
{
	double	delta;
	t_point	new_pos;
	t_player *p;
	double	angle;

	if (keysym < 0 || !g)
		return (1);
	delta = get_delta_time();
	p = &g->player;
	if (keysym == KEY_ESC)
		exit_game(g);
	else if (keysym == KEY_ARROW_LEFT || keysym == KEY_ARROW_RIGHT)
	{
		if (keysym == KEY_ARROW_LEFT)
			angle = P_ROTATE_SPEED * delta;
		else
			angle = -P_ROTATE_SPEED * delta;
		new_pos.x = p->dir.norm.x * cos(angle) - p->dir.norm.y * sin(angle);
		new_pos.y = p->dir.norm.x * sin(angle) + p->dir.norm.y * cos(angle);
		p->dir.norm = new_pos;
		calc_direction(p);
 		set_fov(&p->dir, &p->fov, WIN_WIDTH, 5);
	}
	else
	{
		new_pos = get_new_pos2(p, keysym, delta);
		if(check_new_pos(g->m_data->map, new_pos, p->dir))
		{
			p->location = new_pos;
			p->loc_x = new_pos.x;
			p->loc_y = new_pos.y;
			/* пересчет положения вектора направления */
			calc_direction(p);
 			set_fov(&p->dir, &p->fov, WIN_WIDTH, 5);
		}
	}
	// if (p->ang < 0)
	// 	p->ang += 2 * PI;
	// if (p->ang >= 2 * PI)
	// 	p->ang -= 2 * PI;
	raycast(p, g->wh, WIN_WIDTH, g->m_data->map);
	draw_frame(g->wh, &g->win_mng, &g->main_img, &g->wall);
	return (0);
}

static bool	check_new_pos(char **map, t_point new_pos, t_vector dir)
{
	double new_x;
	double new_y;

	new_x = new_pos.x;
	new_y = new_pos.y;
	//добавляю еще к значению, что бы исключить полложение игрока на границе стены
	if (dir.norm.x > 0)
		new_x += 0.1;
	else if (dir.norm.x < 0)
		new_x -= 0.1;
	if (dir.norm.y > 0)
		new_y += 0.1;
	else if (dir.norm.y < 0)
		new_y -= 0.1;
	return (map[(int)fabs(new_y)][(int)fabs(new_x)] != '1');
}

static t_point	get_new_pos(const t_player *p, int keysym, double delta, double ang)
{
	t_point	new_pos;
	double	factor;

	factor = P_MOVE_SPEED * delta;
	ft_memset(&new_pos, 0, sizeof(t_point));
	if (keysym == KEY_W)
		new_pos = pos_sub(p->location, calc_new_pos(ang + PI / 2, factor));
	else if (keysym == KEY_D)
		new_pos = pos_sum(p->location, calc_new_pos(ang, factor));
	else if (keysym == KEY_S)
		new_pos = (pos_sum(p->location, calc_new_pos(ang + PI / 2, factor)));
	else if (keysym == KEY_A)
		new_pos = (pos_sub(p->location, calc_new_pos(ang, factor)));
	return(new_pos);	
}

static t_point	get_new_pos2(t_player *p, int keysym, double delta)
{
	t_point	new_pos;
	double	factor;

	factor = P_MOVE_SPEED * delta;
	ft_memset(&new_pos, 0, sizeof(t_point));
	if (keysym == KEY_W)
	{
		new_pos.x = p->location.x + p->dir.norm.x * factor;
		new_pos.y = p->location.y + p->dir.norm.y * factor;
	}
	else if (keysym == KEY_D)
	{
		new_pos.x = p->location.x + p->dir.norm.y * factor;
		new_pos.y = p->location.y + p->dir.norm.x * factor * -1;
	}
	else if (keysym == KEY_S)
	{
		new_pos.x = p->location.x - p->dir.norm.x * factor;
		new_pos.y = p->location.y - p->dir.norm.y * factor;
	}
	else if (keysym == KEY_A)
	{
		new_pos.x = p->location.x + p->dir.norm.y * factor * -1;
		new_pos.y = p->location.y + p->dir.norm.x * factor;
	}
	return(new_pos);	
}

static t_point	calc_new_pos(double dir, double factor)
{
	t_point	new_pos;

	new_pos.x = sin(dir) * factor;
	new_pos.y = cos(dir) * factor;
	if (new_pos.y > 0)
		new_pos.y = -new_pos.y;
	return (new_pos);
}
