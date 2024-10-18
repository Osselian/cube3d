#include "../incs/cub3D.h"

void	free_meta(t_meta *meta)
{
	free(meta->no_txtr);
	free(meta->so_txtr);
	free(meta->ea_txtr);
	free(meta->we_txtr);
	free(meta->fl_txtr);
	free(meta->ce_txtr);
	free_arr((void **)meta->map, free_line);
	free(meta);
}
