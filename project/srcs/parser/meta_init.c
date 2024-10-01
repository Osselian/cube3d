#include "../../incs/cub3D.h"

int	meta_init(char **argv, t_meta *metadata)
{
	metadata = (t_meta *)safe_malloc(sizeof(t_meta));
	if (!parse_input(argv, metadata))
	{
		free(metadata);
		return (0);
	}
}
