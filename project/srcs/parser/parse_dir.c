#include "../../incs/cub3D.h"

static int parse_color(t_color *txtr, char *ln)
{
	char	**rgb;
	int		i;

	rgb = ft_split(ln, ',');
	i = 0;
	while (i != 3)
	{
		if (check_color(ft_strtrim(rgb[i], "\n")))
			return (1);
		txtr->c[i] = *ft_strtrim(rgb[i], "\n");
		i++;
	}
	free(rgb);
	return (0);
}

static int	check_texture_ext(char *txtr)
{
	int len;

	len = ft_strlen(txtr);

	if (len < 5 || ft_strncmp((txtr + len - 4), ".png", 4))
	{
		printf(RED"DEBUG: CHECKED TEXTURE EXT <%s>"RESET" %s %d\n", txtr, __FILE__, __LINE__);
		print_error(BAD_TXTR_EXT);
		return (1);
	}
	printf(BLUE"DEBUG: CHECKED TEXTURE EXT <%s>"RESET" %s %d\n", txtr, __FILE__, __LINE__);
	return (0);
}

static int	parse_tfile(char *txtr, char *ln)
{
	int	fd;

	txtr = ft_strdup(ft_strtrim(ln, "\n"));
	if (check_texture_ext(txtr))
		return (1);
	fd = open(txtr, O_RDONLY);
	if (fd == -1)
	{
		print_error(NO_FILE);
		return (1);
	}
	// printf("%s\n", txtr);
	return (0);
}

static int fill_wall(char *ln, int ln_nbr, t_meta *meta)
{
	if (ln_nbr == 0)
		return(parse_tfile(meta->no_txtr, ln));
	else if (ln_nbr == 1)
		return(parse_tfile(meta->so_txtr, ln));
	else if (ln_nbr == 2)
		return(parse_tfile(meta->we_txtr, ln));
	else if (ln_nbr == 3)
		return(parse_tfile(meta->ea_txtr, ln));
	if (ln_nbr == 5)
		return(parse_color(meta->fl_txtr, ln));
	else if (ln_nbr == 6)
		return(parse_color(meta->ce_txtr, ln));
	return (0);
}

int	parse_dir(t_meta *meta, char *ln, long ln_nbr)
{
	char	coords[7][3] = {"NO", "SO", "WE", "EA", "", "F", "C"};
	int		len;

	len = ft_strlen(coords[ln_nbr]);
	if (ft_strncmp(coords[ln_nbr], ln, len) || (ln_nbr != 4 && !ft_isspace(ln[len])))
		return (print_error(INCORRECT_COORDS));
	if ((ln_nbr == 4 || ln_nbr == 7) && ln[0] != '\n')
		return (print_error(INCORRECT_FORMAT));
	if (ln_nbr != 4)
		return(fill_wall(ln + len + 1, ln_nbr, meta));
	return (0);
}
