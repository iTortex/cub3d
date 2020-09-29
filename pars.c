/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:19:13 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 22:29:28 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_for_data(t_file *file)
{
	if (file->win.width != 0 && file->win.height != 0 && file->color.chf != 0
	&& file->sides.east != NULL && file->sides.north != NULL
	&& file->sides.west != NULL && file->sides.south != NULL &&
	file->sprite != NULL && file->color.chc != 0)
		file->check_for_data = 1;
}

static void	res_er(void)
{
	write(2, "RESLUTION ERROR\n", 16);
	exit(0);
}

static void	win(t_file *file)
{
	char **win;

	mlx_get_screen_size(file->img.mlx, &file->win.pc_width,
	&file->win.pc_height);
	if (file->win.width != 0 || file->win.height != 0)
		res_er();
	if (!(win = ft_split(file->line, ' ')))
		res_er();
	if (ft_strlen(win[0]) > 1)
		res_er();
	res_error(win);
	file->win.width = ft_atoi(win[1]);
	file->win.height = ft_atoi(win[2]);
	lets_free(win);
	free(win);
	if (file->win.width < 1 || file->win.height < 1)
		res_er();
	if (file->win.height > file->win.pc_height)
		file->win.height = file->win.pc_height;
	if (file->win.width > file->win.pc_width)
		file->win.width = file->win.pc_width;
}

static void	timeforif(t_file *file)
{
	char **side;
	char *ptr;

	ptr = file->line;
	if (!(file->line = ft_strtrim(file->line, " ")))
		res_er();
	if (!(side = ft_split(file->line, ' ')))
		res_er();
	if (*file->line == 'R')
		win(file);
	if (*file->line == 'F' || *file->line == 'C')
		get_color(file);
	if (ft_strnstr(side[0], "NO", 2) != NULL ||
	ft_strnstr(side[0], "SO", 2) != NULL ||
	ft_strnstr(side[0], "WE", 2) != NULL ||
	ft_strnstr(side[0], "EA", 2) != NULL ||
	ft_strnstr(side[0], "S", 1) != NULL)
		makeside(file);
	free(ptr);
	free(file->line);
	lets_free(side);
	free(side);
}

int			pars(t_file *file)
{
	int i;

	i = ft_strlen(file->line);
	if (file->check_for_data == 1)
		return (1);
	if (i == 0 && file->stop_map == 0)
	{
		ft_bzero(file->line, ft_strlen((file->line)));
		free(file->line);
		return (0);
	}
	if (ft_strnstr(file->line, "S", i) != NULL && file->sprite != NULL &&
	file->sides.south != NULL)
		look_for_map(file);
	if (ft_strnstr(file->line, "NO", i) != NULL ||
	ft_strnstr(file->line, "SO", i) != NULL ||
	ft_strnstr(file->line, "WE", i) != NULL ||
	ft_strnstr(file->line, "EA", i) != NULL ||
	ft_strnstr(file->line, "C", i) != NULL ||
	ft_strnstr(file->line, "R", i) != NULL ||
	ft_strnstr(file->line, "F", i) != NULL ||
	ft_strnstr(file->line, "S", i) != NULL)
		timeforif(file);
	else
		free(file->line);
	check_for_data(file);
	return (0);
}
