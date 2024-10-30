#include "../../incs/cub3D.h"

void	rotate(int keysym, t_player *player, double delta)
{
	double		angle;
	t_point		new_pos;

	if (keysym == KEY_ARROW_LEFT)
	  angle = P_ROTATE_SPEED * delta;
	else
	  angle = -P_ROTATE_SPEED * delta;
	new_pos.x = player->dir.norm.x * cos(angle) - player->dir.norm.y * sin(angle);
	new_pos.y = player->dir.norm.x * sin(angle) + player->dir.norm.y * cos(angle);
	player->dir.norm = new_pos;
	update_direction(player);
	set_fov(&player->dir, &player->fov, WIN_WIDTH, 5);
}