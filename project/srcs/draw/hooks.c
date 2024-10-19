#include "cub3D.h"

int	hooks_init(t_mlx *wm, t_data *g)
{
	if (!wm || !wm->win || !g)
		return (1);
	if (mlx_hook(wm->win, ON_KEYDOWN, KEY_PRESS_MASK, buttons, g))
		return (1);
	if (mlx_hook(wm->win, ON_DESTROY, DESTROY_MASK, exit_game, g))
		return (1);
	return (0);
}
