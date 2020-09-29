/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:13:35 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 13:01:07 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mlx_error(void)
{
	write(2, "MLX ERROR\n", 10);
	exit(0);
}

void		work_begin(t_file *file)
{
	textures(file);
	engine(file);
	mlx_put_image_to_window(file->img.mlx,
	file->img.mlx_win, file->img.img, 0, 0);
	if (file->x_max == 1)
		make_bmp(file);
	new_slide(file);
	mlx_loop(file->img.mlx);
}

void		cub3d(t_file *file)
{
	file->img.mlx = NULL;
	file->img.mlx_win = NULL;
	file->img.img = NULL;
	file->img.data = NULL;
	file->img.mlx = mlx_init();
	while (file->win.height % 64 != 0)
		file->win.height++;
	while (file->win.width % 64 != 0)
		file->win.width++;
	if (!(file->img.mlx_win = mlx_new_window(file->img.mlx,
	file->win.width, file->win.height, "HELLO")))
		mlx_error();
	if (!(file->img.img = mlx_new_image(file->img.mlx,
	file->win.width, file->win.height)))
		mlx_error();
	if (!(file->img.data = (unsigned int *)mlx_get_data_addr(file->img.img,
	&file->img.bpp, &file->img.line_length, &file->img.endian)))
		mlx_error();
	work_begin(file);
}
