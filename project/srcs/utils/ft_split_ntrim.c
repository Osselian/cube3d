#include "../../incs/cub3D.h"

static void	fill_str(char *p1, char *p2, char **arr, int count)
{
	int	len;
	int	i;

	i = 0;
	len = p2 - p1;
	printf("len: %d, str: %s\n", len, p1);
	arr[count] = (char *)malloc(sizeof(char) * (len + 1));
	while (p1 != p2)
	{
		arr[count][i] = *p1;
		p1++;
		i++;
	}
	arr[count][i] = 0;
}

static void	fill_arr(const char *str, char c, char **arr)
{
	size_t	count;
	char	*p1;
	char	*p2;

	count = 0;
	p1 = (char *)str;
	p2 = (char *)str;
	while (*p2)
	{
		p2 = ft_strchr(p2, c);
		fill_str(p1, p2, arr, count);
		count++;
		p2++;
		p1 = p2;
	}
	fill_str(p1, p2, arr, count);
}

static size_t	count_words(const char *str, char c)
{
	char	*occ;
	size_t	count;

	count = 0;
	while (*str)
	{
		occ = ft_strchr(str, c);
		if (occ)
		{
			str = occ + 1;
			count++;
		}
		else
			break ;
	}
	if (count == 0)
		return (0);
	return (count + 1);
}

char	**ft_split_ntrim(char const *s, char c)
{
	size_t count;
	size_t len;
	char **arr;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	count = count_words(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fill_arr(s, c, arr);
	arr[count] = NULL;
	return (arr);
}