/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:00:06 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 15:22:35 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	data_error(void)
{
	write(2, "DATA ERROR\n", 11);
	exit(0);
}
