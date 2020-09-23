#include "cub3d.h"

void	map_error(void)
{
	write(2, "THIS MAP IS BULLSHIT\n", 21);
	exit(0);
}

void	check_walls(char **map, int x, int y, int i)
{
	int j;

	j = ft_strlen(map[x]);
	if (x < 0 || x >= i || y < 0 || y >= j)
		map_error();
	if (map[x][y] == '1' ||  map[x][y] == '5')
		return ;
	if (map[x][y] == '0' || map[x][y] == '2')
		map[x][y] = '5';
	if (map[x][y] == ' ')
		map_error();
	check_walls(map, x, y + 1, i);
	check_walls(map, x, y - 1, i);
	check_walls(map, x + 1, y, i);
	check_walls(map, x - 1, y, i);
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
	if (file->stop_gamer != 1)
		map_error();
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
	check_walls(file->map, x, y, i);
	return (0);
}