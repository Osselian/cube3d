#include "../../incs/cub3D.h"

static t_point	get_new_pos(const t_player *p, int keysym, double delta, double ang);
static t_point	calc_new_pos(double dir, double factor);
static t_point	calc_direction( t_player *p);

int	exit_game(t_data *data)
{
	free_data(data);
	exit(0);
}

static t_point	calc_direction( t_player *p)
{
	t_point	new_pos;
	
	// new_pos.x = p->location.x + p->dir.len * cos(p->ang);
	// new_pos.y = p->location.y + p->dir.len * sin(p->ang);
    p->dir.val.x = p->location.x + p->dir.norm.x * p->dir.len;
    p->dir.val.y = p->location.y + p->dir.norm.y * p->dir.len;
    return (new_pos);
}

int	buttons(int keysym, t_data *g)
{
	double	delta;
	t_point	new_pos;
	t_player *p;

	if (keysym < 0 || !g)
		return (1);
	delta = get_delta_time();
	p = &g->player;
	if (keysym == KEY_ESC)
		exit_game(g);
	else if (keysym == KEY_ARROW_LEFT){
		p->ang += P_ROTATE_SPEED * delta;
		double r = P_ROTATE_SPEED * delta;
		//new_pos.x = fabs(p->dir.val.x * cos(r) - p->dir.val.y * sin(r));
		//new_pos.y = p->dir.val.x * sin(r) + p->dir.val.y * cos(r);
		new_pos.x = p->dir.norm.x * cos(r) - p->dir.norm.y * sin(r);
		new_pos.y = p->dir.norm.x * sin(r) + p->dir.norm.y * cos(r);
		p->dir.norm = new_pos;
		calc_direction(p);
		printf("old dir: x: %f y: %f\nnew dir = x: %f y: %f\n", p->dir.val.x, p->dir.val.y, new_pos.x, new_pos.y);
		// p->dir.val = new_pos;
 		set_fov(&p->dir, &p->fov, WIN_WIDTH, 5);
		printf("FOV: start.x=%f start.y=%f end.x=%f end.y=%f\n", p->fov.start.x, p->fov.start.y, p->fov.end.x, p->fov.end.y);
	}
	else if (keysym == KEY_ARROW_RIGHT){
		p->ang -= P_ROTATE_SPEED * delta;

		/*	new_pos.x = fabs(p->dir.val.x * cos(r) - p->dir.val.y * sin(r));
			new_pos.y = -(p->dir.val.x * sin(r)) + p->dir.val.y * cos(r);	
			эквивалентно расчету calc_direction: */
		new_pos = calc_direction(p);
		printf("old dir = x: %f y: %f\nnew dir = x: %f y: %f\n", p->dir.val.x, p->dir.val.y, new_pos.x, new_pos.y);

		p->dir.val = new_pos;
 		set_fov(&p->dir, &p->fov, WIN_WIDTH, 5);
		printf("FOV: start.x = %f start.y = %f end.x=%f end.y=%f\n", p->fov.start.x, p->fov.start.y, p->fov.end.x, p->fov.end.y);
	}
	else
	{
		new_pos = get_new_pos(p, keysym, delta, p->ang);
		if (g->m_data->map[(int)fabs(new_pos.y)][(int)fabs(new_pos.x)] != '1'){
			p->location = new_pos;
			p->loc_x = new_pos.x;
			p->loc_y = new_pos.y;
			/* пересчет положения вектора направления */
			new_pos = calc_direction(p);
			p->dir.val= new_pos;
 			set_fov(&p->dir, &p->fov, WIN_WIDTH, 5);
		}
	}
	if (p->ang < 0)
		p->ang += 2 * PI;
	if (p->ang >= 2 * PI)
		p->ang -= 2 * PI;
	raycast(p, g->wh, WIN_WIDTH, g->m_data->map);
	draw_frame(g->wh, &g->win_mng, &g->main_img, &g->wall);
	return (0);
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

static t_point	calc_new_pos(double dir, double factor)
{
	t_point	new_pos;

	new_pos.x = sin(dir) * factor;
	new_pos.y = cos(dir) * factor;
	if (new_pos.y > 0)
		new_pos.y = -new_pos.y;
	return (new_pos);
}
