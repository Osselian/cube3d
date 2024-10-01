/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:42:38 by sosokin           #+#    #+#             */
/*   Updated: 2024/02/03 17:09:07 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fdlist
{
	int				fd;
	char			*rem;
	struct s_fdlist	*next;
}					t_list;

char	*ft_strchr(const char *s, int c);

char	*ft_stradd(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
#endif
