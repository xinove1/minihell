#include "minihell.h"

void	free_2darray(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
