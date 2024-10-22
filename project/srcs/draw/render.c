#include "cub3D.h"

# define P1 M_PI_2
# define P3 4.71239

static double	fix_ang(double a);
static t_text	*select_texture(double r_ang, t_text *t, int is_vert);
static void		put_pixel(int x, int y, t_img *img, int color);
static void		draw_wall(t_render_info *i, int x, int y);
static void		wall_setup(t_render_info *s, const t_text *t, double dist, double off);

void draw_frame(const t_data *g)
{
	int					i;
	double				p_ang;
	double				r_ang;
	double				dist;
	t_text				*wall;
	t_render_info		s;

	if (!g)
		return ;
	i = -1;
	p_ang = fix_ang(atan2(g->player.dir.norm.x, g->player.dir.norm.y));
	while (++i < WIN_WIDTH)
	{
		r_ang = fix_ang(atan2(g->wh[i].hit.x, g->wh[i].hit.y));
		wall = select_texture(r_ang, g->wall, g->wh[i].is_vert);
		dist = fabs(g->wh[i].distance * cos(fabs(p_ang - r_ang)));
		wall_setup(&s, wall, dist, g->wh[i].offset);
		s.img = (t_img *)&g->main_img;
		draw_vertical_line(&s, i);
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

static t_text *select_texture(double r_ang, t_text *t, int is_vert)
{
	t_text	*wall;

	if (!t || r_ang < 0)
		return (NULL);
	if (is_vert)
	{
		if (r_ang > 0 && r_ang < M_PI)
			wall = t + 2;
		else
			wall = t + 3;
	}
	else
	{
		if (r_ang > P1 && r_ang < P3)
			wall = t;
		else
			wall = t + 1;
	}
	return (wall);
}

static void	wall_setup(t_render_info *s, const t_text *t, double dist, double off)
{
	ft_memset(s, 0, sizeof(t_render_info));
	s->t = (t_text *)t;
	s->wall_offset = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
	s->floor_offset = WIN_HEIGHT - s->wall_offset;
	s->tx = (int)(off * t->width) % t->width;
	s->wall_height = s->floor_offset - s->wall_offset;
	s->ty_step = (double)t->height / s->wall_height;
	if (s->wall_height > WIN_HEIGHT)
	{
		s->ty_off = fabs(WIN_HEIGHT / 2.0 - s->wall_height / 2.0); 
		s->wall_height = WIN_HEIGHT;
	}
	s->ty = s->ty_off * s->ty_step;
}

void draw_vertical_line(t_render_info *i, int x)
{
	int	y;

	y = -1;
	while (++y < i->wall_offset)
		put_pixel(x, y, i->img, W_BLUE);
	draw_wall(i, x, y);
	y += i->floor_offset - y;
	while (++y < WIN_HEIGHT)
		put_pixel(x, y, i->img, W_GREEN);
}

static void	draw_wall(t_render_info *i, int x, int y)
{
	int 	index;

	while (y < i->floor_offset && y < WIN_HEIGHT)
	{
		index = (int)(i->ty) * i->t->width + (int)(i->tx);
  		put_pixel(x, y, i->img, ((int *)i->t->img.data_addr)[index]); 
		i->ty += i->ty_step;
		y++;
	}
}

static void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !img || color < 0)
		return ;
	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->data_addr + offset) = color;
}
