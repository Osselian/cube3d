/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:53 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:54 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"
#include <stdbool.h>

static int	ext_check(char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (file[i] != '.')
		i++;
	if (file[i + 1] != 'c' || file[i + 2] != 'u' || file[i + 3] != 'b'
		|| file[i + 4] != '\0')
	{
		print_error(INCORRECT_FILE);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(NO_FILE);
	return (fd);
}

static bool	try_parse_map(long *ln_nbr, t_meta *metadata, char *ln)
{
	if (*ln_nbr == INT_MAX)
	{
		print_error(LONGMAP);
		return (false);
	}
	if (parse_map(metadata, ln))
		return (false);
	return (true);
}

static int	parse_line(int fd, t_meta *metadata)
{
	char	*ln;
	long	ln_nbr;

	ln_nbr = 0;
	ln = get_next_line(fd);
	while (ln && *ln)
	{
		if (!(ln_nbr <= 5 && ln[0] == '\n'))
		{
			if (ln_nbr <= 5)
			{
				if (parse_dir(metadata, ln, &ln_nbr))
				{
					free(ln);
					return (1);
				}
			}
			else if (!try_parse_map(&ln_nbr, metadata, ln))
				return (1);
			ln_nbr++;
		}
		free(ln);
		ln = get_next_line(fd);
	}
	free(ln);
	return (0);
}

int	fill_map_arr(t_meta *metadata)
{
	metadata->map = ft_split(metadata->map_str, '\n');
	if (!metadata->map)
	{
		print_error(FATAL);
		return (1);
	}
	return (0);
}

int	parser(char **argv, t_meta *metadata)
{
	int	fd;

	fd = ext_check(argv[1]);
	if (fd < 0)
		return (1);
	if (parse_line(fd, metadata))
	{
		close(fd);
		return (1);
	}
	if (fill_map_arr(metadata))
		return (1);
	if (check_map(metadata, metadata->map))
		return (1);
	return (0);
}
