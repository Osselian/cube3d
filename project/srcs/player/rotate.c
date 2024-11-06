#include "../../incs/cub3D.h"

void	rotate(int keysym, t_player *player, double delta)
{
	double		angle;
	t_point		new_pos;
	double		dir_x;
	double		dir_y;

	if (keysym == KEY_ARROW_LEFT)
		angle = P_ROTATE_SPEED * delta;
	else
		angle = -P_ROTATE_SPEED * delta;
	dir_x = player->dir.norm.x;
	dir_y = player->dir.norm.y;
	new_pos.x = dir_x * cos(angle) - dir_y * sin(angle);
	new_pos.y = dir_x * sin(angle) + dir_y * cos(angle);
	player->dir.norm = new_pos;
	update_direction(player);
	set_fov(&player->dir, &player->fov, WIN_WIDTH, 5);
}
