#include "cub3d.h"

static void	make_map(t_file *file)
{
	int i;
	int x;

	x = 0;
	i = ft_lstsize(file->head);
	printf("%d\n", i);
	if (!(file->map = malloc(sizeof(char **) * (i + 1))))
		exit(0);
	while (x != i)
	{
		if (!(file->map[x] = ft_strdup(file->first->content)))
			exit(0);
		file->first = file->first->next;
		x++;
	}
	file->map[i] = NULL;
}

static void	check_gamer(t_file *file)
{
	if (file->stop_gamer == 1)
	{
		write(2, "GAMER ERROR\n", 12);
		exit(0);
	}
}

static void	ifsides(t_file *file, int y, int x)
{
	if (file->map[y][x] == 'N')
	{
		check_gamer(file);
		file->game.posx = y + 0.5;
		file->game.posy = x + 0.5;
		file->game.dirx = -1;
		file->game.diry = 0;
		file->game.planex = 0;
		file->game.planey = 1;
		file->map[y][x] = '0';
		file->stop_gamer = 1;
	}
	if (file->map[y][x] == 'S')
	{
		check_gamer(file);
		file->game.posx = y + 0.5;
		file->game.posy = x + 0.5;
		file->game.dirx = 0;
		file->game.diry = 1;
		file->game.planex = 1;
		file->game.planey = 0;
		file->map[y][x] = '0';
		file->stop_gamer = 1;
	}
	if (file->map[y][x] == 'W')
	{
		check_gamer(file);
		file->game.posx = y + 0.5;
		file->game.posy = x + 0.5;
		file->game.dirx = 0;
		file->game.diry = -1;
		file->game.planex = -1;
		file->game.planey = 0;
		file->map[y][x] = '0';
		file->stop_gamer = 1;
	}
	if (file->map[y][x] == 'E')
	{
		check_gamer(file);
		file->game.posx = y + 0.5;
		file->game.posy = x + 0.5;
		file->game.dirx = 1;
		file->game.diry = 0;
		file->game.planex = 0;
		file->game.planey = 1;
		file->map[y][x] = '0';
		file->stop_gamer = 1;
	}
	if (file->map[y][x] == '2')
		file->spritesum += 1;
}


void	onlymap(t_file *file)
{
	int x;
	int y;
	int i;

	i = 0;
	file->spritesum = 0;
	x = 0;
	y = 0;
	make_map(file);
	while (file->map[y])
	{
		x = 0;
		while (file->map[y][x])
		{
			ifsides(file, y, x);
			x++;
		}
		y++;
	}
	if (!(file->game.sx = ft_calloc(file->spritesum + 1, sizeof(double))))
		exit(0);
	if (!(file->game.sy = ft_calloc(file->spritesum + 1, sizeof(double))))
		exit(0);
	if (!(file->game.spritedistance = ft_calloc(file->spritesum + 1, sizeof(double))))
		exit(0);
	x = 0;
	y = 0;
	if (file->map[y][x])
	{
		while (file->map[y])
		{
			x = 0;
			while (file->map[y][x])
			{
				if (file->map[y][x] == '2')
				{
					file->game.sx[i] = y + 0.5;
					file->game.sy[i] = x + 0.5;
					i++;
				}
				x++;
			}
			y++;
		}
	}
}