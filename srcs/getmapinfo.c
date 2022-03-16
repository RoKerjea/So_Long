/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmapinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:30:14 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/16 19:30:19 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	searchposition(t_mapdata *mapdata)
{
	int	x;
	int	y;

	y = 0;
	while (mapdata->map[y])
	{
		x = 0;
		while (mapdata->map[y][x])
		{
			if (mapdata->map[y][x] == 'P')
			{
				mapdata->pos[0] = y;
				mapdata->pos[1] = x;
			}
			x++;
		}
		y++;
	}
}

void	countitems(t_mapdata *mapdata)
{
	int	y;
	int	x;

	y = 0;
	mapdata->itemcount = 0;
	while (mapdata->map[y])
	{
		x = 0;
		while (mapdata->map[y][x])
		{
			if (mapdata->map[y][x] == 'C')
				mapdata->itemcount++;
			x++;
		}
		y++;
	}
	mapdata->height = y;
	mapdata->length = x;
}

void	getmapinfo(t_mapdata *mapdata)
{
	mapdata->movcount = 0;
	searchposition(mapdata);
	countitems(mapdata);
}

