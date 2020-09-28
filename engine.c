#include "cub3d.h"
#include <math.h>

static void	nextstepsecond(t_file *file)
{
		file->game.sidedisty += file->game.deltadisty;
		file->game.mapy += file->game.stepy;
		file->game.side = 1;
}

static void	nextstep(t_file *file)
{
	if (file->game.raydiry < 0)
	{
		file->game.stepy = -1;
		file->game.sidedisty = (file->game.posy - file->game.mapy) * file->game.deltadisty;
	}
	else 
	{
		file->game.stepy = 1;
		file->game.sidedisty = (file->game.mapy + 1.0 - file->game.posy) * file->game.deltadisty;
	}
	while (file->game.hit == 0)
	{
		if (file->game.sidedistx < file->game.sidedisty)
		{
			file->game.sidedistx += file->game.deltadistx;
			file->game.mapx += file->game.stepx;
			file->game.side = 0;
		}
		else
			nextstepsecond(file);
		if (file->map[file->game.mapx][file->game.mapy] == '1' && file->game.hit == 0)
			file->game.hit = 1;
	}
	draw(file);
}

static void	firstwhile(t_file *file)
{
	while (file->ioooo < file->win.width)
	{
		file->game.camerax = 2 * (double)file->ioooo / (double)file->win.width - 1;
		file->game.raydirx = file->game.dirx + file->game.planex * file->game.camerax;
		file->game.raydiry = file->game.diry + file->game.planey * file->game.camerax;
		file->game.mapx = (int)file->game.posx;
		file->game.mapy = (int)file->game.posy;
		file->game.deltadistx = fabs(1 / file->game.raydirx);
		file->game.deltadisty = fabs(1 / file->game.raydiry);
		file->game.hit = 0;
		if (file->game.raydirx < 0)
		{
			file->game.stepx = -1;
			file->game.sidedistx = (file->game.posx - file->game.mapx) * file->game.deltadistx;
		}
		else 
		{
			file->game.stepx = 1;
			file->game.sidedistx = (file->game.mapx + 1.0 - file->game.posx) * file->game.deltadistx;
		}
		nextstep(file);
		file->ioooo++;
	}
}

void	engine(t_file *file)
{
	file->ioooo = 0;
	file->game.zbuffer = ft_calloc(file->win.width + 1, sizeof(double));
	firstwhile(file);
	draw_sprite(file);
	free(file->game.zbuffer);
}