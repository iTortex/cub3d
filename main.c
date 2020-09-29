/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:09:29 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 22:27:18 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	inv_file(void)
{
	write(2, "INVALID FILE\n", 13);
	exit(0);
}

static void	check_res(t_file *file)
{
	if (file->win.height == 0 || file->win.width == 0)
		inv_file();
	if (file->sides.west == NULL || file->sides.north == NULL ||
	file->sides.east == NULL || file->sides.south == NULL)
		inv_file();
	if (file->color.chc == 0 || file->color.chf == 0)
		inv_file();
	if (file->stop_map == 0)
		inv_file();
}

static void	init(t_file *file)
{
	file->win.height = 0;
	file->win.width = 0;
	file->sides.south = NULL;
	file->sides.north = NULL;
	file->sides.east = NULL;
	file->sides.west = NULL;
	file->color.chc = 0;
	file->color.chf = 0;
	file->sprite = NULL;
	file->stop_map = 0;
	file->stop_gamer = 0;
	file->check_for_data = 0;
	file->first = NULL;
	file->map = NULL;
	file->y_max = 0;
	file->x_max = 0;
}

void		lets_gnl(t_file *file, int flag)
{
	while (get_next_line(file->fd, &file->line))
	{
		if (flag == 0)
		{
			if (pars(file) == 1)
				flag = 1;
		}
		if (flag == 1)
			look_for_map(file);
	}
	look_for_map(file);
	check_res(file);
	onlymap(file);
	flood_fill(file);
	cub3d(file);
}

int			main(int argc, char **argv)
{
	t_file	file;
	char	*check;
	int		flag;

	flag = 0;
	if (argc != 2 && argc != 3)
		inv_file();
	if (!(check = ft_substr(argv[1], ft_strlen(argv[1]) - 4,
	ft_strlen(argv[1]))))
		inv_file();
	if (ft_strnstr(check, ".cub", ft_strlen(argv[1])) == NULL)
		inv_file();
	free(check);
	init(&file);
	if (argc == 3)
	{
		file.x_max = 1;
		if (ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) != 0 ||
		(ft_strlen(argv[2])) < 6)
			inv_file();
	}
	if (!(file.fd = open(argv[1], O_RDONLY)))
		inv_file();
	lets_gnl(&file, flag);
	return (0);
}
