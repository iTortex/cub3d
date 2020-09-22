#include "cub3d.h"

static void	make_map(t_file *file)
{
	int i;
	int x;
	int j;
	char *ptr;

	j = 1;
	x = 0;
	i = ft_lstsize(file->first);
	file->map = ft_calloc(i, sizeof(char **));
	while (j != i)
	{
		ptr = file->map[x];
		file->map[x] = ft_strdup(file->first->content);
		free(ptr);
		ft_lstdelone(file->first, free);
		file->first = file->first->next;
		// free(file->first->content);
		j++;
		x++;
	}
}

void	check_gamer(t_file *file)
{
	if (file->stop_gamer == 1)
	{
		write(2, "GAMER ERROR\n", 12);
		exit(0);
	}
}

void	ifsides(t_file *file, int y, int x)
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
	// printf("%c\n", file->map[y][x]);
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

// void	ifsprite(t_file *file, int y, int x, int i)
// {
// 	if (file->map[y][x] == '2')
// 	{
// 		file->game.spriteorder[i] = i;
// 		file->game.sx[i] = x;
// 		file->game.sy[i] = y;
// 	}
// }

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
	if (file->map[y][x])
	{
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
	}
	// file->game.spriteorder = ft_calloc(file->spritesum, sizeof(int));
	file->game.sx = ft_calloc(file->spritesum, sizeof(double));
	file->game.sy = ft_calloc(file->spritesum, sizeof(double));
	file->game.spritedistance = ft_calloc(file->spritesum, sizeof(int));
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
					// file->game.spriteorder[i] = i;
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