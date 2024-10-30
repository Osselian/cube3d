#include "../../incs/cub3D.h"

int	on_key_pressed(int keysym, t_data *g)
{
	double	delta;
	t_player *p;

	if (keysym < 0 || !g)
		return (1);
	delta = get_delta_time();
	p = &g->player;
	if (keysym == KEY_ESC)
		exit_game(g);
	else if (keysym == KEY_ARROW_LEFT || keysym == KEY_ARROW_RIGHT)
		rotate(keysym, &g->player, delta);
	else
		move(keysym, g, delta);
	raycast(p, g->wh, WIN_WIDTH, g->m_data->map);
	draw_frame(g);
	return (0);
}