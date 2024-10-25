#include "../../incs/cub3D.h"

char	**ft_arrmemcpy(void **dst, const void **src, size_t size)
{
	size_t	i;
	char	**ndst;
	char	**nsrc;

	i = 0;
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	if (!src && !dst)
		return ((char **)dst);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	ndst = (char **)dst;
	nsrc = (char **)src;
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	while (i < size - 1)
	{
		printf(G"DEBUG %s %d %zu %zu"RESET"\n", __FILE__, __LINE__, i, size - 1);
		if (nsrc && nsrc[i])
			ndst[i] = ft_memcpy((void *)(ndst[i]), (void *)(nsrc[i]), ft_strlen(nsrc[i]));
		i++;
	}
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	return ((char **)dst);
}
