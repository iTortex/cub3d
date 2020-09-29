/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:22:21 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 21:39:07 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_error(void)
{
	write(2, "THIS MAP IS BULLSHIT\n", 21);
	exit(0);
}

static void	check_walls(char **map, int x, int y, t_file *file)
{
	if (x < 0 || x > file->f_i || y < 0 || y > file->f_j)
		map_error();
	file->f_j = ft_strlen(map[x]);
	if (x < 0 || x > file->f_i || y < 0 || y > file->f_j)
		map_error();
	if (map[x][y] == '1' || map[x][y] == '5')
		return ;
	if (map[x][y] == '0' || map[x][y] == '2')
		map[x][y] = '5';
	if (map[x][y] == ' ')
		map_error();
	check_walls(map, x, y + 1, file);
	check_walls(map, x, y - 1, file);
	check_walls(map, x - 1, y, file);
	check_walls(map, x + 1, y, file);
}

int			flood_fill(t_file *file)
{
	int x;
	int y;

	file->f_i = 0;
	file->f_j = 0;
	if (file->stop_gamer != 1)
		map_error();
	while (file->map[file->f_i])
		file->f_i++;
	file->f_i -= 1;
	x = (int)file->game.posx;
	y = (int)file->game.posy;
	if (!file->map[x + 1])
		map_error();
	file->f_j = ft_strlen(file->map[x]);
	check_walls(file->map, x, y, file);
	return (0);
}
