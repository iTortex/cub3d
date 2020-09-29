/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:19:59 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 15:20:14 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn_right(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	file->game.olddirx = file->game.dirx;
	file->game.dirx = file->game.dirx * cos(-0.1) -
	file->game.diry * sin(-0.1);
	file->game.diry = file->game.olddirx * sin(-0.1) +
	file->game.diry * cos(-0.1);
	file->game.raydirx = file->game.raydirx * cos(-0.1) -
	file->game.raydiry * sin(-0.1);
	file->game.raydiry = file->game.raydirx * sin(-0.1) +
	file->game.raydiry * cos(-0.1);
	file->game.oldplanex = file->game.planex;
	file->game.planex = file->game.planex * cos(-0.1) -
	file->game.planey * sin(-0.1);
	file->game.planey = file->game.oldplanex * sin(-0.1) +
	file->game.planey * cos(-0.1);
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win,
	file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
}

static void	turn_left(t_file *file)
{
	mlx_clear_window(file->img.mlx, file->img.mlx_win);
	file->game.olddirx = file->game.dirx;
	file->game.dirx = file->game.dirx * cos(0.1) -
	file->game.diry * sin(0.1);
	file->game.diry = file->game.olddirx * sin(0.1) +
	file->game.diry * cos(0.1);
	file->game.raydirx = file->game.raydirx * cos(0.1) -
	file->game.raydiry * sin(0.1);
	file->game.raydiry = file->game.raydirx * sin(0.1) +
	file->game.raydiry * cos(0.1);
	file->game.oldplanex = file->game.planex;
	file->game.planex = file->game.planex * cos(0.1) -
	file->game.planey * sin(0.1);
	file->game.planey = file->game.oldplanex * sin(0.1) +
	file->game.planey * cos(0.1);
	engine(file);
	mlx_put_image_to_window(file->img.mlx, file->img.mlx_win,
	file->img.img, 0, 0);
	mlx_do_sync(file->img.mlx);
}

void		turn(int key, t_file *file)
{
	if (key == 123)
		turn_left(file);
	if (key == 124)
		turn_right(file);
}
