/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:40:22 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 13:42:34 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	next_step(t_file *file)
{
	file->game.wallx -= (int)file->game.wallx;
	file->game.texx = (int)(file->game.wallx * (double)file->game.texwidth);
	if (file->game.side == 0 && file->game.raydirx > 0)
		file->game.texx = file->game.texwidth - file->game.texx - 1;
	if (file->game.side == 1 && file->game.raydiry < 0)
		file->game.texx = file->game.texwidth - file->game.texx - 1;
	file->game.step = 1.0 * file->game.texheight / file->game.lineheight;
	file->game.texpos = (file->game.drawstart - file->win.height / 2 +
	file->game.lineheight / 2) * file->game.step;
}

static void	someif(t_file *file)
{
	if (file->game.side == 0)
		file->game.perpwalldist = (file->game.mapx - file->game.posx +
		(double)(1.0 - file->game.stepx) / 2) / file->game.raydirx;
	else
		file->game.perpwalldist = (file->game.mapy - file->game.posy +
		(double)(1.0 - file->game.stepy) / 2) / file->game.raydiry;
	file->game.lineheight = (int)(file->win.height / file->game.perpwalldist);
	file->game.drawstart = -(file->game.lineheight) / 2 + file->win.height / 2;
	if (file->game.drawstart <= 0)
		file->game.drawstart = 0;
	if (file->game.drawstart >= file->win.width)
		file->game.drawstart = file->win.width - 1;
	file->game.drawend = file->game.lineheight / 2 + file->win.height / 2;
	if (file->game.drawend >= file->win.height)
		file->game.drawend = file->win.height - 1;
	if (file->game.side == 0)
		file->game.wallx = file->game.posy +
		file->game.perpwalldist * file->game.raydiry;
	else
		file->game.wallx = file->game.posx +
		file->game.perpwalldist * file->game.raydirx;
	next_step(file);
}

static void	drawwalls(t_file *file)
{
	while (file->game.drawstart < file->game.drawend)
	{
		file->game.texy = (int)file->game.texpos & (file->game.texheight - 1);
		file->game.texpos += file->game.step;
		if (file->game.side == 0 && file->game.raydirx < 0)
			file->clr = my_mlx_pixel_take(&file->texn,
			file->game.texx, file->game.texy);
		else if (file->game.side == 0 && file->game.raydirx >= 0)
			file->clr = my_mlx_pixel_take(&file->texw,
			file->game.texx, file->game.texy);
		else if (file->game.side == 1 && file->game.raydiry < 0)
			file->clr = my_mlx_pixel_take(&file->texs,
			file->game.texx, file->game.texy);
		else if (file->game.side == 1 && file->game.raydiry >= 0)
			file->clr = my_mlx_pixel_take(&file->texe,
			file->game.texx, file->game.texy);
		my_mlx_pixel_put(&file->img, file->ioooo,
		file->game.drawstart, file->clr);
		file->game.drawstart++;
	}
}

void		draw(t_file *file)
{
	int x;
	int y;

	someif(file);
	x = 0;
	y = file->game.drawend;
	while (x < file->game.drawstart)
	{
		my_mlx_pixel_put(&file->img, file->ioooo, x, file->color.clrf);
		x++;
	}
	while (y < file->win.height - 1)
	{
		my_mlx_pixel_put(&file->img, file->ioooo, y, file->color.clrc);
		y++;
	}
	drawwalls(file);
	file->game.zbuffer[file->ioooo] = file->game.perpwalldist;
}
