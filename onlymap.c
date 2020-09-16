#include "cub3d.h"

static void	make_map(t_file *file)
{
	int i;
	int j;

	j = 0;
	i = ft_lstsize(file->first);
	file->map = ft_calloc(i + 1, sizeof(char **));
	while (j != i)
	{
		file->map[j] = ft_strdup(file->first->content);
		ft_bzero(file->first->content, ft_strlen(file->first->content));
		free(file->first->content);
		file->first = file->first->next;
		j++;
	}
}

void	ifsides(t_file *file, int y, int x)
{
	if (file->map[y][x] == 'N')
	{
		file->game.posx = x + 0.5;
		file->game.posy = y + 0.5;
		file->game.dirx = 0;
		file->game.diry = 1;
		file->game.planex = 1;
		file->game.planey = 0;
	}
	if (file->map[y][x] == 'S')
	{
		file->game.posx = x + 0.5;
		file->game.posy = y + 0.5;
		file->game.dirx = 0;
		file->game.diry = -1;
		file->game.planex = -1;
		file->game.planey = 0;
	}
	if (file->map[y][x] == 'W')
	{
		file->game.posx = x + 0.5;
		file->game.posy = y + 0.5;
		file->game.dirx = -1;
		file->game.diry = 0;
		file->game.planex = 0;
		file->game.planey = -1;
	}
	if (file->map[y][x] == 'E')
	{
		file->game.posx = x + 0.5;
		file->game.posy = y + 0.5;
		file->game.dirx = 1;
		file->game.diry = 0;
		file->game.planex = 0;
		file->game.planey = 1;
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
	file->game.spriteorder = ft_calloc(file->spritesum, sizeof(int));
	file->game.sx = ft_calloc(file->spritesum, sizeof(int));
	file->game.sy = ft_calloc(file->spritesum, sizeof(int));
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
					file->game.spriteorder[i] = i;
					file->game.sx[i] = x;
					file->game.sy[i] = y;
					i++;
				}
				x++;
			}
			y++;
		}
	}
}