#ifndef CUB3D
# define CUB3D

# include <unistd.h>
//# include "mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "../libs/get_next_line/get_next_line.h"
//#include "mlx_int.h"

typedef struct s_txtr
{
	bool	is_txtr; //FALSE for color, TRUE for texture
	char	*txtr_val;
}	t_txtr;

typedef struct s_meta
{
	t_txtr	*no_txtr;
	t_txtr	*so_txtr;
	t_txtr	*we_txtr;
	t_txtr	*ea_txtr;
	t_txtr	*fl_txtr;
	t_txtr	*ce_txtr;
	char	**map;
}	t_meta;

int		print_error(char *mes);
int		parse_input(char **argv, t_meta *metadata);
int		meta_init(char **argv, t_meta *metadata);
void	*safe_malloc(size_t str);

#endif