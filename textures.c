/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:48:34 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 12:51:07 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		mlx_error(void)
{
	write(2, "MLX ERROR\n", 10);
	exit(0);
}

static void		tex_next(t_file *file)
{
	file->texw.data = (unsigned int *)mlx_get_data_addr(file->texw.img,
	&file->texw.bpp, &file->texw.line_length, &file->texw.endian);
	if ((file->texs.img = mlx_xpm_file_to_image(file->img.mlx,
	file->sides.south, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texs.data = (unsigned int *)mlx_get_data_addr(file->texs.img,
	&file->texs.bpp, &file->texs.line_length, &file->texs.endian);
	if ((file->sprites.img = mlx_xpm_file_to_image(file->img.mlx,
	file->sprite, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->sprites.data = (unsigned int *)mlx_get_data_addr(file->sprites.img,
	&file->sprites.bpp, &file->sprites.line_length, &file->sprites.endian);
}

void			textures(t_file *file)
{
	if ((file->texn.img = mlx_xpm_file_to_image(file->img.mlx,
	file->sides.north, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texn.data = (unsigned int *)mlx_get_data_addr(file->texn.img,
	&file->texn.bpp, &file->texn.line_length, &file->texn.endian);
	if ((file->texe.img = mlx_xpm_file_to_image(file->img.mlx,
	file->sides.east, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	file->texe.data = (unsigned int *)mlx_get_data_addr(file->texe.img,
	&file->texe.bpp, &file->texe.line_length, &file->texe.endian);
	if ((file->texw.img = mlx_xpm_file_to_image(file->img.mlx,
	file->sides.west, &file->game.texwidth, &file->game.texheight)) == 0)
		mlx_error();
	tex_next(file);
}
