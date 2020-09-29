/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onlymap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:36:40 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 20:30:43 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	some_if(t_file *file)
{
	if (!(file->game.sx = ft_calloc(file->spritesum + 1, sizeof(double))))
		exit(0);
	if (!(file->game.sy = ft_calloc(file->spritesum + 1, sizeof(double))))
		exit(0);
	if (!(file->game.spritedistance = ft_calloc(file->spritesum + 1,
	sizeof(double))))
		exit(0);
}

static void	moreif(t_file *file, int i)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (file->map[y][x])
	{
		while (file->map[y])
		{
			x = 0;
			while (file->map[y][x])
			{
				if (file->map[y][x] == '2')
				{
					file->game.sx[i] = y + 0.5;
					file->game.sy[i] = x + 0.5;
					i++;
				}
				x++;
			}
			y++;
		}
	}
}

static void	make_map(t_file *file)
{
	int i;
	int x;

	x = 0;
	i = ft_lstsize(file->head);
	if (!(file->map = malloc(sizeof(char **) * (i + 1))))
		exit(0);
	while (x != i)
	{
		if (!(file->map[x] = ft_strdup(file->first->content)))
			exit(0);
		file->first = file->first->next;
		x++;
	}
	file->map[i] = NULL;
}

void		onlymap(t_file *file)
{
	int x;
	int y;
	int i;

	i = 0;
	file->spritesum = 0;
	x = 0;
	y = 0;
	make_map(file);
	while (file->map[y])
	{
		x = 0;
		while (file->map[y][x])
		{
			ifsides(file, y, x);
			x++;
		}
		y++;
	}
	some_if(file);
	moreif(file, i);
}
