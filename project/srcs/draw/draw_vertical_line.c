
#include "../../incs/cub3D.h"

static void		put_pixel(int x, int y, t_img *img, int color);
static void		draw_wall(t_render_info *i, int x, int y);

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