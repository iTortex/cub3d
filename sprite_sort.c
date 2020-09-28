#include "cub3d.h"

static void	swap_pos(t_file *file, int i, int j)
{
	double sx;
	double sy;

	sx = file->game.sx[i];
	sy = file->game.sy[i];
	file->game.sx[i] = file->game.sx[j];
	file->game.sy[i] = file->game.sy[j];
	file->game.sx[j] = sx;
	file->game.sy[j] = sy;
}

void	sprite_sort(t_file *file)
{
	int i;
	int j;
	double dist;

	i = 0;
	j = 0;
	while (i < file->spritesum)
	{
		j = 0;
		while (j < file->spritesum)
		{
			if (file->game.spritedistance[i] >= file->game.spritedistance[j])
			{
				dist = file->game.spritedistance[i];
				file->game.spritedistance[i] = file->game.spritedistance[j];
				file->game.spritedistance[j] = dist;
				swap_pos(file, i, j);
			}
			j++;
		}
		i++;
	}
}