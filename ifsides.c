/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ifsides.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:40:54 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 17:55:54 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_gamer(t_file *file)
{
	if (file->stop_gamer == 1)
	{
		write(2, "GAMER ERROR\n", 12);
		exit(0);
	}
}

static void	forw(t_file *file, int y, int x)
{
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
}

static void	fors(t_file *file, int y, int x)
{
	if (file->map[y][x] == 'S')
	{
		check_gamer(file);
		file->game.posx = y + 0.5;
		file->game.posy = x + 0.5;
		file->game.dirx = 1;
		file->game.diry = 0;
		file->game.planex = 0;
		file->game.planey = -1;
		file->map[y][x] = '0';
		file->stop_gamer = 1;
	}
}

static void	fore(t_file *file, int y, int x)
{
	if (file->map[y][x] == 'E')
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
	if (file->map[y][x] == '2')
		file->spritesum += 1;
}

void		ifsides(t_file *file, int y, int x)
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
	fors(file, y, x);
	forw(file, y, x);
	fore(file, y, x);
}
