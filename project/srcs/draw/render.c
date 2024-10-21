#include "cub3D.h"
#define P1 M_PI_2
#define P3 4.71239

t_text *select_texture(double r_ang, t_text *t, int is_vert)
{
	t_text	*wall;

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

void draw_frame(t_wallhit *w, t_mlx *wm, t_img *img, t_text *t, t_player *p)
{
	int		i;
	t_text	*wall;
	double	p_ang;
	double	r_ang;
	double	dist;

    i = -1;
    p_ang = atan2(p->dir.norm.x, p->dir.norm.y);
	if (p_ang < 0)
		p_ang += 2 * PI;
	if (p_ang >= 2 * PI)
		p_ang -= 2 * PI;
	while (++i < WIN_WIDTH)
	{
		r_ang = atan2(w[i].hit.x, w[i].hit.y);
		if (r_ang < 0)
			r_ang += 2 * PI;
		if (r_ang >= 2 * PI)
			r_ang -= 2 * PI;
		wall = select_texture(r_ang, t, w[i].is_vert);
		dist = fabs(w[i].distance * cos(fabs(p_ang - r_ang)));
		draw_vertical_line(wall, img, dist, i, w[i].offset);
	}
	mlx_put_image_to_window(wm->mlx, wm->win, img->data, 0, 0);
}

void draw_vertical_line(t_text *t, t_img *img, double dist, int x, double off)
{
	if (!img || !t || !t->img.data_addr)
		return;
	int color;
    int wall = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
    int floor = WIN_HEIGHT - wall;
	int y;
 	int wall_height;

	double tx = (int)(off * t->width) % t->width;
	double ty_off=0;
	int index;
	double ty_step;
	double ty = 0.0;
	y = -1;

	while (++y < wall)
		put_pixel(x, y, img, W_BLUE);

	wall_height = floor - y;
	ty_step = (double)t->height / wall_height;
	if (wall_height > WIN_HEIGHT)
	{
		ty_off = fabs(WIN_HEIGHT / 2.0 - wall_height / 2.0); 
		wall_height = WIN_HEIGHT;
	}
	ty = ty_off * ty_step;
	while (y < floor && y < WIN_HEIGHT)
	{
		index = (int)(ty) * t->width + (int)(tx);
		if (index > 64 * 64)
			index = index % t->width;
		color = ((int *)t->img.data_addr)[index];
		ty += ty_step;
  		put_pixel(x, y, img, color);
		y++;
	}
	while (++y < WIN_HEIGHT)
		put_pixel(x, y, img, W_GREEN);
}

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !img || color < 0)
		return ;
	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->data_addr + offset) = color;
}
