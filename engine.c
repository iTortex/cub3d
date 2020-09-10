#include "cub3d.h"
#include <math.h>

#define mapWidth 24
#define mapHeight 24

static void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    unsigned int    *dst;

    dst = data->data + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	nextstepthird(t_file *file)
{
	if (file->game.side == 0)
		file->game.perpwalldist = (file->game.mapx - file->game.posx + (double)(1.0 - file->game.stepx) / 2) / file->game.raydirx;
	else
		file->game.perpwalldist = (file->game.mapy - file->game.posy + (double)(1.0 - file->game.stepy) / 2) / file->game.raydiry;
	file->game.lineheight = (int)(file->win.height / file->game.perpwalldist);
	file->game.drawstart = -(file->game.lineheight) / 2 + file->win.height / 2;
	if (file->game.drawstart < 0)
		file->game.drawstart = 0;
	file->game.drawend = file->game.lineheight / 2 + file->win.height / 2;
	if (file->game.drawend >= file->win.height)
		file->game.drawend = file->win.height - 1;
	// if (file->game.side == 1)
	// 	file->clr = (file->clr / 2);
	for (int x = 0; x < file->game.drawstart; x++)
		my_mlx_pixel_put(&file->img, file->ioooo, x, file->color.clrf);
	for (int y = file->game.drawend; y < file->win.height; y++)
		my_mlx_pixel_put(&file->img, file->ioooo, y, file->color.clrc);
	for (; file->game.drawstart < file->game.drawend; file->game.drawstart++)
		my_mlx_pixel_put(&file->img, file->ioooo, file->game.drawstart, file->clr);
}

void	nextstepsecond(t_file *file)
{
		file->game.sidedisty += file->game.deltadisty;
		file->game.mapy += file->game.stepy;
		file->game.side = 1;
}

void	nextstep(t_file *file)
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
		if (file->map[file->game.mapy][file->game.mapx] == '1' && file->map[file->game.mapy][file->game.mapx])
			file->game.hit = 1;
	}
	nextstepthird(file);
}

void	engine(t_file *file)
{
	file->ioooo = 0;
	while (file->ioooo < file->win.width)
	{
		file->game.camerax = 2 * file->ioooo / (double)file->win.width - 1;
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