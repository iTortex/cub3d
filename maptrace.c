/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maptrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:17:00 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 14:17:09 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	maptrace(t_file *file)
{
	static _Bool flag;

	file->stop_map = 1;
	if (file->color.chc == 0 || file->color.chf == 0)
	{
		write(2, "COLOR ERROR\n", 12);
		exit(0);
	}
	ft_lstadd_back(&file->first, ft_lstnew(file->line));
	if (!flag)
	{
		flag = 1;
		file->head = file->first;
	}
}
