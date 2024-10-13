#include "../../incs/cub3D.h"

int	meta_init(char **argv, t_meta *metadata)
{
	metadata = (t_meta *)safe_malloc(sizeof(t_meta));
	metadata->no_txtr = (t_txtr *)safe_malloc(sizeof(t_txtr));
	metadata->so_txtr = (t_txtr *)safe_malloc(sizeof(t_txtr));
	metadata->ea_txtr = (t_txtr *)safe_malloc(sizeof(t_txtr));
	metadata->we_txtr = (t_txtr *)safe_malloc(sizeof(t_txtr));
	metadata->fl_txtr = (t_txtr *)safe_malloc(sizeof(t_txtr));
	metadata->ce_txtr = (t_txtr *)safe_malloc(sizeof(t_txtr));
	metadata->ok_flg = true;
	metadata->map = (char **)safe_malloc(sizeof(char *));
	if (parse_input(argv, metadata))
	{
		free(metadata);
		return (0);
	}
	return (0);
}
