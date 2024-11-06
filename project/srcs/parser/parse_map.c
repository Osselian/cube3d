/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:18:11 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:18:15 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static int	check_map_row(char *ln)
{
	unsigned int	i;

	i = 0;
	if (ln[0] == '\n')
	{
		free(ln);
		return (print_error(EMPTYLINEINMAP));
	}	
	while ((ln[i] != '\0' && ln[i] != '\n'))
	{
		if (i == INT_MAX)
		{
			print_error(LONGMAP);
			return (1);
		}
		if (!(ln[i] == '0' || ln[i] == '1' || ln[i] == 'N'
				|| ln[i] == 'W' || ln[i] == 'E' || ln[i] == 'S'
				|| ln[i] == ' ' || ln[i] == 9))
		{
			free(ln);
			return (print_error(INCORRECT_MAP_SYMBOL));
		}
		i++;
	}
	return (0);
}

int	parse_map(t_meta *meta, char *ln)
{
	char	*tmp;

	if (check_map_row(ln))
		return (1);
	tmp = meta->map_str;
	meta->map_str = ft_strjoin(meta->map_str, ln);
	free(tmp);
	return (0);
}
