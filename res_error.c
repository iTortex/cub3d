/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:17:44 by amarcele          #+#    #+#             */
/*   Updated: 2020/09/29 15:18:10 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	mistake(void)
{
	write(2, "RESLUTION ERROR\n", 16);
	exit(0);
}

static void	one_more_while(char **win, int x, int i)
{
	while (win[1][x] >= '1' && win[1][x] <= '9')
	{
		if (i > i + 5)
		{
			win[1] = "10000";
			break ;
		}
		x++;
	}
}

static void	first_while(char **win, int i, int j)
{
	while (win[i])
		i++;
	if (i != 3)
		mistake();
	i = 0;
	while (win[1][i] >= '0' && win[1][i] <= '9')
		i++;
	while (win[2][j] >= '0' && win[2][j] <= '9')
		j++;
	if (win[2][j] != '\0' || win[1][i] != '\0')
		mistake();
	i = 0;
	j = 0;
	while (win[1][i] == '0')
		i++;
	while (win[2][j] == '0')
		j++;
}

void		res_error(char **win)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	first_while(win, i, j);
	x = i;
	y = j;
	one_more_while(win, x, i);
	while (win[2][y] >= '1' && win[2][y] <= '9')
	{
		if (y > i + 5)
		{
			win[2] = "10000";
			break ;
		}
		y++;
	}
}
