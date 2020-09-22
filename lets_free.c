#include "cub3d.h"

void	lets_free(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while(str[i])
	{
		free(str[i]);
		i++;
	}
}