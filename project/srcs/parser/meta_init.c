#include "../../incs/cub3D.h"

t_meta	*meta_init(char **argv)
{
	t_meta	*metadata;

	metadata = (t_meta *)safe_malloc(sizeof(t_meta));
	// metadata->no_txtr = (char *)safe_malloc(sizeof(char));
	// metadata->so_txtr = (char *)safe_malloc(sizeof(char));
	// metadata->ea_txtr = (char *)safe_malloc(sizeof(char));
	// metadata->we_txtr = (char *)safe_malloc(sizeof(char));
	metadata->fl_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->ce_txtr = (t_color *)safe_malloc(sizeof(t_color));
	// metadata->map = (char **)safe_malloc(sizeof(char *));
	metadata->map_str = (char *)safe_malloc(sizeof(char *));
	metadata->maplen = 0;
	metadata->player_pos[0] = -1;
	if (parser(argv, metadata))
	{
		free_meta(metadata);
		return (NULL);
	}
	return (metadata);
}
