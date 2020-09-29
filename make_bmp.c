/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:12:08 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 14:12:25 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_bmp(t_file *file)
{
	char	*add;
	int		memory;
	int		i;

	memory = file->win.width * file->win.height * (file->img.bpp >> 3) + 54;
	add = ft_calloc(memory + 1, sizeof(char));
	ft_memcpy(&add[0], "BM", 2);
	ft_memcpy(&add[2], &memory, 4);
	i = 54;
	ft_memcpy(&add[10], &i, 4);
	i = 40;
	ft_memcpy(&add[14], &i, 4);
	ft_memcpy(&add[18], &file->win.width, 4);
	file->win.height = -file->win.height;
	ft_memcpy(&add[22], &file->win.height, 4);
	i = 1;
	ft_memcpy(&add[26], &i, 2);
	ft_memcpy(&add[28], &file->img.bpp, 2);
	ft_memcpy(&add[54], file->img.data, memory - 54);
	i = open("map.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	write(i, add, memory);
	free(add);
	close(i);
	exit(0);
}
