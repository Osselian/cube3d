#include "../../incs/cub3D.h"

static char	**init_coords(char **coords)
{
	coords = (char **)safe_malloc(8 * sizeof(char *));
	coords[0] = ft_strdup("NO");
	coords[1] = ft_strdup("SO");
	coords[2] = ft_strdup("WE");
	coords[3] = ft_strdup("EA");
	coords[4] = ft_strdup("");
	coords[5] = ft_strdup("F");
	coords[6] = ft_strdup("C");
	coords[7] = ft_strdup("\0");
	return (coords);
}

int	parse_dir(t_meta *meta, char *ln, long ln_nbr)
{
	char	**coords;
	int		len;
	
	coords = NULL;
	coords = init_coords(coords);
	len = ft_strlen(coords[ln_nbr]);
	if (ft_strncmp(coords[ln_nbr], ln, len) || (ln_nbr != 4 && !ft_isspace(ln[len])))
	{
		free_arr((void **)coords, free_line);
		return (print_error(INCORRECT_COORDS));
	}
	//free_arr((void **)coords, free_line);
	if ((ln_nbr == 4 || ln_nbr == 7) && ln[0] != '\n')
		return (print_error(INCORRECT_FORMAT));
	if (!(ln_nbr == 4 || ln_nbr == 7))
	{
		return(fill_wall(ln + len + 1, ln_nbr, meta));
	}
	return (0);
}
