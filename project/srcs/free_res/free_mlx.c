#include "../../incs/cub3D.h"

void	free_mlx(t_mlx *wm, void *main_img, void *text)
{
	if (!wm)
		return ;
	mlx_destroy_image(wm->mlx, main_img);
	mlx_destroy_image(wm->mlx, text);
	mlx_destroy_window(wm->mlx, wm->win);
	#ifdef __linux__
		mlx_destroy_display(wm->mlx);
	#endif


}