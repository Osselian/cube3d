/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:17:41 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:42 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static int	check_txtr_input(char *ln, char ***txtrs)
{
	char	**txtrs_arr;
	int		i;
	int		res;

	i = 0;
	res = 0;
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	txtrs_arr = ft_split_ntrim(ln, ' ');
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (txtrs_arr && txtrs_arr[2] && txtrs_arr[2][0] != '\0')
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		free_arr((void **)txtrs_arr, free);
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		return (res);
	}
	while (txtrs[i])
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		if (!ft_strcmp(txtrs_arr[0], txtrs[i][0]))
		{
			printf("DEBUG %s %d\n", __FILE__, __LINE__);
			if (!txtrs[i][1] || txtrs[i][1][0] == '\0')
			{
				txtrs[i][1] = ft_strdup(txtrs_arr[1]);
				res = 1;
			}
			printf("DEBUG %s %d\n", __FILE__, __LINE__);
			free_arr((void **)txtrs_arr, free);
			printf("DEBUG %s %d\n", __FILE__, __LINE__);
			return (res);
		}
		i++;
	}
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	free_arr((void **)txtrs_arr, free);
	return (res);
}

static int	check_full_txtrs(char ***txtrs)
{
	int	i;

	i = 0;
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	while (i <= 5)
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		if (!txtrs[i][1] || txtrs[i][1][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	parse_dir(t_meta *meta, char *ln, bool *texture_flg)
{
	if (ln[0] == '\n')
		return (0);
	if (!check_txtr_input(ln, meta->txtrs))
		return (print_error(INCORRECT_COORDS));
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	if (check_full_txtrs(meta->txtrs))
	{
		printf("DEBUG %s %d\n", __FILE__, __LINE__);
		*texture_flg = true;
		return (fill_wall(meta));
	}
	printf("DEBUG %s %d\n", __FILE__, __LINE__);
	return (0);
}
