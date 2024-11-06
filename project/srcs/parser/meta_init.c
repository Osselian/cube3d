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

t_meta	*meta_init(char **argv)
{
	t_meta	*metadata;

	metadata = (t_meta *)safe_malloc(sizeof(t_meta));
	metadata->fl_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->ce_txtr = (t_color *)safe_malloc(sizeof(t_color));
	metadata->map_str = (char *)safe_malloc(sizeof(char *));
	metadata->maplen = 0;
	metadata->player_pos[0] = -1;
	if (parser(argv, metadata))
	{
		free_meta(metadata);
		return (NULL);
	}
	system("leaks cub3D");
	return (metadata);
}
