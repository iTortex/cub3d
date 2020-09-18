#include "cub3d.h"

void	mistake(void)
{
	write(2, "RESLUTION ERROR\n", 16);
	exit(0);
}

void	res_error(char **win)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (win[i])
		i++;
	if (i != 3)
		mistake();
	i = 0;
	while (win[1][i] >= '0' && win[1][i] <= '9')
		i++;
	while (win[2][j] >= '0' && win[2][j] <= '9')
		j++;
	if (win[2][j] != '\0' || win[1][i] != '\0')
		mistake();
	i = 0;
	j = 0;
	while (win[1][i] >= '0' && win[1][i] <= '9')
	{
		if (i > 4)
		{
			win[1] = "10000";
			break;
		}
		i++;
	}
	while (win[2][j] >= '0' && win[2][j] <= '9')
	{
		if (j > 4)
		{
			win[2] = "10000";
			break;
		}
		j++;
	}
}