#include "../../incs/cub3D.h"

char	**ft_realloc(char **ptr, size_t size)
{
	char **new;

	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	new = (char **)safe_malloc(sizeof(char *) * (size + 1));
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	if (!new)
		return (NULL);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	new = ft_arrmemcpy((void **)new, (const void **)ptr, size);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	free_arr((void **)ptr, free);
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	ptr = new;
	printf(G"DEBUG %s %d"RESET"\n", __FILE__, __LINE__);
	return (ptr);
}
