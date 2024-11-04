#include "../../incs/cub3D.h"

static double	fix_ang(double a);
static t_text	*select_texture(t_text *t, char orient);
static void		wall_setup(t_render_info *s, const t_text *t, double dist, double off);

void draw_frame(const t_data *g)
{
	int					i;
	double				p_ang;
	double				r_ang;
	double				dist;
	t_text				*wall;
	t_render_info		render_info;

	if (!g)
		return ;
	i = -1;
	p_ang = fix_ang(atan2(g->player.dir.norm.x, g->player.dir.norm.y));
	while (++i < WIN_WIDTH)
	{
		r_ang = fix_ang(atan2(g->wh[i].hit.x, g->wh[i].hit.y));
		wall = select_texture(g->wall, g->wh[i].orientation);
		dist = fabs(g->wh[i].distance * cos(fabs(p_ang - r_ang)));
		wall_setup(&render_info, wall, dist, g->wh[i].offset);
		render_info.img = (t_img *)&g->main_img;
		draw_vertical_line(&render_info, i, g->m_data);
	}
	mlx_put_image_to_window(g->win_mng.mlx, g->win_mng.win, g->main_img.data, 0, 0);
}

static double	fix_ang(double a)
{
	if (a < 0)
		a += 2.0 * PI;
	if (a >= 2.0 * PI)
		a -= 2.0 * PI;
	return (a);
}

static t_text *select_texture(t_text *t, char orient)
{
	t_text	*wall;

	if (orient == 's')
		wall = t;	
	else if (orient == 'n')
		wall = t + 1;
	else if (orient == 'e')
		wall = t + 2;
	else if (orient == 'w')
		wall = t + 3;
	return (wall);
}

static void	wall_setup(
	t_render_info *r_info, const t_text *t, double dist, double off)
{
	ft_memset(r_info, 0, sizeof(t_render_info));
	r_info->t = (t_text *)t;
	r_info->wall_offset = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
	r_info->floor_offset = WIN_HEIGHT - r_info->wall_offset;
	r_info->wall_height = r_info->floor_offset - r_info->wall_offset;
	r_info->tx = (int)(off * t->width) % t->width;
	r_info->ty_step = (double)t->height / r_info->wall_height;
	if (r_info->wall_height > WIN_HEIGHT)
	{
		r_info->ty_off = fabs(WIN_HEIGHT / 2.0 - r_info->wall_height / 2.0); 
		r_info->wall_height = WIN_HEIGHT;
	}
	r_info->ty = r_info->ty_off * r_info->ty_step;
}