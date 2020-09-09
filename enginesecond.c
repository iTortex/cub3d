#include "cub3d.h"
#include <math.h>

static void            my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    unsigned int    *dst;

    dst = data->data + (y * data->line_length + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}

void	enginesecond(t_file *file)
{
	double c;
	double x;
	double y;
	int		i;
	double	angle;

	c = 0.05;
	i = 0;
	x = file->game.posx;
	y = file->game.posy;
	while(i < file->win.width)
	{
		angle = file->game.player_an - M_PI / 6 + M_PI / 3 * i / file->win.width;
		while (file->map[(int)y][(int)x] != '1')
		{
			x = file->game.posx + c * cos(angle);
			y = file->game.posy + c * sin(angle);
			c += 0.05;
		}
		file->game.dirx = x;
		file->game.diry = y;
		file->game.perpwalldist = (sqrt(pow(x - file->game.posx, 2) + pow(y - file->game.posy, 2)));
		// if (file->game.perpwalldist < 1)
		// 	file->game.perpwalldist += 1;
		file->game.lineheight = file->win.height / file->game.perpwalldist;
		file->game.drawstart = -file->game.lineheight / 2 + file->win.height / 2;
		file->game.drawend = file->game.lineheight / 2 + file->win.height / 2;
		while (file->game.drawstart < file->game.drawend)
		{
			my_mlx_pixel_put(&file->img, i, file->game.drawstart, file->clr);
			file->game.drawstart++;
		}
		i++;
	}
}