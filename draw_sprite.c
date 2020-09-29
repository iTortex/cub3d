/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:33:57 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 13:38:06 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		lets_put(t_file *file, int yy, int stripe)
{
	while (yy < file->game.drawendy - 1)
	{
		file->game.d = (yy) * 256 - file->win.height * 128 +
		file->game.spriteheight * 128;
		file->game.texy = ((file->game.d * file->game.texheight) /
		file->game.spriteheight) / 256;
		file->clr = my_mlx_pixel_take(&file->sprites,
		file->game.texx, file->game.texy);
		if ((file->clr & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&file->img, stripe, yy, file->clr);
		yy++;
	}
}

static void	sprite_while_next(t_file *file)
{
	int stripe;
	int yy;

	yy = 0;
	stripe = file->game.drawstartx;
	while (stripe < file->game.drawendx - 1)
	{
		file->game.texx = (int)(256 * (stripe - (-file->game.spritewidth /
		2 + file->game.spritescreenx)) * file->game.texwidth
		/ file->game.spritewidth) / 256;
		if (file->game.transformy > 0 && stripe > 0 && stripe <
		file->win.width && file->game.transformy <
		file->game.zbuffer[stripe])
		{
			yy = file->game.drawstarty;
			lets_put(file, yy, stripe);
		}
		stripe++;
	}
}

static void	sprite_while(t_file *file)
{
	file->game.spritescreenx = (int)((file->win.width / 2) *
	(1 + file->game.transformx / file->game.transformy));
	file->game.spriteheight = fabs((file->win.height / file->game.transformy));
	file->game.drawstarty = -file->game.spriteheight / 2 +
	file->win.height / 2;
	if (file->game.drawstarty < 0)
		file->game.drawstarty = 0;
	file->game.drawendy = file->game.spriteheight / 2 + file->win.height / 2;
	if (file->game.drawendy >= file->win.height)
		file->game.drawendy = file->win.height - 1;
	file->game.spritewidth = fabs((file->win.height / file->game.transformy));
	file->game.drawstartx = -file->game.spritewidth / 2 +
	file->game.spritescreenx;
	if (file->game.drawstartx < 0)
		file->game.drawstartx = 0;
	file->game.drawendx = file->game.spritewidth / 2 +
	file->game.spritescreenx;
	if (file->game.drawendx >= file->win.width)
		file->game.drawendx = file->win.width - 1;
	sprite_while_next(file);
}

static void	first_while(t_file *file, int i)
{
	while (i < file->spritesum)
	{
		file->game.spritedistance[i] = ((file->game.posx - file->game.sx[i]) *
		(file->game.posx - file->game.sx[i]) +
		(file->game.posy - file->game.sy[i]) *
		(file->game.posy - file->game.sy[i]));
		i++;
	}
}

void		draw_sprite(t_file *file)
{
	int i;
	int j;

	i = 0;
	j = 0;
	first_while(file, i);
	sprite_sort(file);
	while (j < file->spritesum)
	{
		file->game.spritex = file->game.sx[j] - file->game.posx;
		file->game.spritey = file->game.sy[j] - file->game.posy;
		file->game.invdet = 1.0 / (file->game.planex * file->game.diry -
		file->game.dirx * file->game.planey);
		file->game.transformx = file->game.invdet * (file->game.diry *
		file->game.spritex - file->game.dirx * file->game.spritey);
		file->game.transformy = file->game.invdet * (-file->game.planey *
		file->game.spritex + file->game.planex * file->game.spritey);
		sprite_while(file);
		j++;
	}
}
