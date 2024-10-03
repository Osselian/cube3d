#include "../../incs/cub3D.h"

static int fill_w_elem(t_txtr *txtr, char *ln)
{
	int	i;

	i = 0;
	txtr->is_txtr = false;
	while (ln[i] != '\0')
	{
		if (!ft_isdigit(ln[i]) || ln[i] != '.')
		{
			txtr->is_txtr = true;
			break;
		}
		i++;
	}
	txtr->txtr_val = ft_strdup(ln);
	return (0);
}

static int fill_wall(char *ln, int ln_nbr, t_meta *meta)
{
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (ln_nbr == 0)
		fill_w_elem(meta->no_txtr, ln);
	else if (ln_nbr == 1)
		fill_w_elem(meta->so_txtr, ln);
	else if (ln_nbr == 2)
		fill_w_elem(meta->we_txtr, ln);
	else if (ln_nbr == 3)
		fill_w_elem(meta->ea_txtr, ln);
	else if (ln_nbr == 5)
		fill_w_elem(meta->fl_txtr, ln);
	else if (ln_nbr == 6)
		fill_w_elem(meta->ce_txtr, ln);
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
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
	if (ln_nbr != 4)
		fill_wall(ln + len + 1, ln_nbr, meta); //TODO если ошибка
	return (0);
}
