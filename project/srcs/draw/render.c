#include "cub3D.h"

void	draw_frame(t_wallhit *w, t_mlx *wm, t_img *img, t_text *t)
{
	int 	i;

	i = -1;
	while (++i < WIN_WIDTH)
	{
		//printf("distance = %f\n", w[i].distance);
		draw_vertical_line(t, img, w[i].distance, i);
	}
	mlx_put_image_to_window(wm->mlx, wm->win, img->data, 0, 0);
}

void draw_vertical_line(t_text *t, t_img *img, double dist, int x)
{
    if (!img || !t || !t->img.data_addr)
        return;
	
	int c;
    int wall = (int)(WIN_HEIGHT / 2 - WIN_HEIGHT * FOV / dist);
    int floor = WIN_HEIGHT - wall;

 	int lineH;

	double tx = (int)(x) % 64;
	double ty_off=0;
	int index;
    double ty_step;
    double ty = 0.0;
    for (int y = 0; y < WIN_HEIGHT; y++)
    {
        if (y < wall)
            c = BLUE; 
        else if (y >= wall && y < floor)
        {
			lineH = floor - y;
			ty_step = (double)t->height / lineH;
 			if (lineH > WIN_HEIGHT)
			{
				ty_off=fabs(WIN_HEIGHT / 2.0 - lineH / 2.0); 
				lineH=WIN_HEIGHT;
			}
			ty = ty_off * ty_step;
			for(int i = 0; i < lineH; ++i)
			{
				index = (int)(ty) * t->width + (int)(tx);
				if (index > 64 * 64)
					index = index % 64;
				c = ((int *)t->img.data_addr)[index];
 		       	ty += ty_step;
       			put_pixel(x, y, img, c);
				y++;
			}
			continue ;
        }
		else
            c = GREEN;
        put_pixel(x, y, img, c);
	}
}

void	put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || y < 0 || !img || color < 0)
		return ;
	offset = (y * img->size_line) + (x * (img->bits_per_pixel / 8));
	*(int *)(img->data_addr + offset) = color;
}