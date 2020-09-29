/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_take.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:07:17 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 14:18:12 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		my_mlx_pixel_take(t_img *data, int x, int y)
{
	unsigned int	*dst;
	unsigned int	color;

	dst = data->data + (y * data->line_length + x * (data->bpp / 8));
	color = *(unsigned int*)dst;
	return (color);
}
