#include "../../incs/cub3D.h"

static int	check_texture_ext(char *txtr)
{
	int len;

	len = ft_strlen(txtr);

	if (len < 5 || ft_strncmp((txtr + len - 4), ".xpm", 4))
	{
		print_error(BAD_TXTR_EXT);
		return (1);
	}
	return (0);
}

static int	parse_color(t_color *txtr, char *ln)
{
	char	**rgb;
	int		i;
	int		j;
	char	*tmp;

	rgb = ft_split(ln, ',');
	txtr->c[3] = 0;
	i = 0;
	j = 2;
	while (i != 3)
	{
		if (check_color(ft_strtrim(rgb[i], "\n")))
			return (1);
		tmp = ft_strtrim(rgb[i], "\n");
		txtr->c[j] = ft_atoi(tmp);
		free(tmp);
		j--;
		i++;
	}
	free_arr((void **)rgb, free);
	return (0);
}

static int	parse_tfile(char **txtr, char *ln)
{
	int	fd;

	*txtr = ft_strtrim(ln, "\n");
	if (check_texture_ext(*txtr))
		return (1);
	fd = open(*txtr, O_RDONLY);
	if (fd == -1)
	{
		print_error(NO_FILE);
		return (1);
	}
	return (0);
}

int	fill_wall(char *ln, int ln_nbr, t_meta *meta)
{
	if (ln_nbr == 0)
		return (parse_tfile(&(meta->no_txtr), ln));
	else if (ln_nbr == 1)
		return (parse_tfile(&(meta->so_txtr), ln));
	else if (ln_nbr == 2)
		return (parse_tfile(&(meta->we_txtr), ln));
	else if (ln_nbr == 3)
		return (parse_tfile(&(meta->ea_txtr), ln));
	if (ln_nbr == 5)
		return (parse_color(meta->fl_txtr, ln));
	else if (ln_nbr == 6)
		return (parse_color(meta->ce_txtr, ln));
	return (0);
}
