/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: defimova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:21:20 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 17:21:21 by defimova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

bool	check_color(char *ln)
{
	int	i;

	i = 0;
	while (ln[i] != '\0')
	{
		if (!ft_isdigit(ln[i]))
		{
			print_error(INCORRECT_COLOR);
			free(ln);
			return (true);
		}
		i++;
	}
	if (ft_atoi(ln) < 0 || ft_atoi(ln) > 255)
	{
		print_error(INCORRECT_COLOR);
		free(ln);
		return (true);
	}
	free(ln);
	return (false);
}
