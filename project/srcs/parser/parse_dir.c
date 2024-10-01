#include "../../incs/cub3D.h"

static int fill_wall(char *ln, int ln_nbr, t_meta *meta)
{
	// printf("DEBUG %s %d\n", __FILE__, __LINE__);

	return (0);
}

int	parse_dir(t_meta *meta, char *ln, int ln_nbr)
{
	char	coords[7][3] = {"NO", "SO", "WE", "EA", "", "F", "C"};
	int		len;

	len = ft_strlen(coords[ln_nbr]);
	if (ft_strncmp(coords[ln_nbr], ln, len) || (ln_nbr != 4 && !ft_isspace(ln[len])))
		return (print_error(INCORRECT_COORDS));
	if (ln_nbr == 4 && ln[0] != '\n')
		return (print_error(INCORRECT_FORMAT));
	fill_wall(ln + len + 1, ln_nbr, meta); //TODO если ошибка
	return (0);
}
