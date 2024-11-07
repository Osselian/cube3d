/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:17 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 22:03:26 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static char	***init_coords(char ***coords)
{
	int	i;

	i = 0;
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	coords = (char ***)safe_malloc(7 * sizeof(char ***));
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	while (i <= 6)
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		coords[i++] = (char **)safe_malloc(2 * sizeof(char **));
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
	}
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	coords[0][0] = ft_strdup("NO");
	coords[1][0] = ft_strdup("SO");
	coords[2][0] = ft_strdup("WE");
	coords[3][0] = ft_strdup("EA");
	coords[4][0] = ft_strdup("F");
	coords[5][0] = ft_strdup("C");
	coords[6][0] = ft_strdup("\0");
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	return (coords);
}

t_meta	*meta_init(char **argv)
{
	t_meta	*metadata;

	metadata = (t_meta *)safe_malloc(sizeof(t_meta));
	metadata->fl_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->ce_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->map_str = (char *)safe_malloc(sizeof(char *));
	metadata->maplen = 0;
	metadata->player_pos[0] = -1;
	metadata->txtrs = init_coords(metadata->txtrs);
	if (parser(argv, metadata))
	{
		free_meta(metadata);
		system("leaks cub3D");
		return (NULL);
	}
	system("leaks cub3D");
	return (metadata);
}
