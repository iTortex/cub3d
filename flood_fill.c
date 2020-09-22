#include "cub3d.h"

void	map_error(void)
{
	write(2, "THIS MAP IS BULLSHIT\n", 21);
	exit(0);
}

void	check_walls(char **map, int x, int y, int i, int j)
{
	if (x < 0 || x >= i || y < 0 || y >= j)
		map_error();
	if (map[x][y] == '1' || map[x][y] == '3')
		return ;
	if (map[x][y] == '0' || map[x][y] == '2')
		map[x][y] = '3';
	check_walls(map, x, y + 1, i, j);
	check_walls(map, x, y - 1, i, j);
	check_walls(map, x + 1, y, i, j);
	check_walls(map, x - 1, y, i, j);
}

int		flood_fill(t_file *file)
{
	int x;
	int y;
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = j;
	while(file->map[i])
	{
		j = 0;
		while(file->map[i][j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	x = (int)file->game.posx;
	y = (int)file->game.posy;
	check_walls(file->map, x, y, i, max);
	return (0);
}