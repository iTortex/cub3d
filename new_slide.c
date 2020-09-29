/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_slide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:18:28 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 14:18:45 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		exitt(void)
{
	exit(0);
	return (0);
}

void			new_slide(t_file *file)
{
	mlx_hook(file->img.mlx_win, 2, 0, wasd, file);
	mlx_hook(file->img.mlx_win, 17, 0, exitt, file);
}
