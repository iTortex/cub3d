#include "cub3d.h"

static void	map_error(void)
{
	write(2, "THIS MAP IS BULLSHIT\n", 21);
	exit(0);
}

static void	check_walls(char **map, int x, int y, int i, int j)
{

	if (x < 0 || x > i || y < 0 || y > j)
		map_error();
	j = ft_strlen(map[x]);
	if (x < 0 || x > i || y < 0 || y > j)
		map_error();
	if (map[x][y] == '1' ||  map[x][y] == '5')
		return ;
	if (map[x][y] == '0' || map[x][y] == '2')
		map[x][y] = '5';
	if (map[x][y] == ' ')
		map_error();
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

	i = 0;
	j = 0;
	if (file->stop_gamer != 1)
		map_error();
	while(file->map[i])
		i++;
	printf("%i\n", i);
	i -= 1;
	x = (int)file->game.posx;
	y = (int)file->game.posy;
	j = ft_strlen(file->map[x]);
	check_walls(file->map, x, y, i, j);
	return (0);
}