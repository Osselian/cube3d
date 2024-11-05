#include "../../incs/cub3D.h"

t_data	*free_data(t_data *g)
{
	free(g->wh);
	free_meta(g->m_data);
	free_mlx(&g->win_mng, g->main_img.data, g->wall[0].img.data);
	free(g->wall);
	free(g);
	return (NULL);
}
