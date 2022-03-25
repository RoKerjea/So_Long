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

int	searchposition(t_mapdata *mapdata)
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
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
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

char	*cpymap(char **tab)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = "\n";
	line = "\n";
	while (tab[i])
	{
		tmp = ft_strjoin(line, "\n");
		if (ft_strlen(line) > 1)
			free(line);
		if (!tmp)
			return (NULL);
		line = strdup(tmp);
		free (tmp);
		tmp = ft_strjoin(line, tab[i]);
		free (line);
		if (!tmp)
			return (NULL);
		line = strdup(tmp);
		free (tmp);
		i++;
	}
	return (line);
}

void	getmapinfo(t_mapdata *mapdata)
{
	int	y;
	int	x;

	y = 0;
	mapdata->movcount = 0;
	searchposition(mapdata);
	countitems(mapdata);
	while (mapdata->prevmap[y])
	{
		x = 0;
		while (mapdata->prevmap[y][x])
		{
			mapdata->prevmap[y][x] = 'X';
			x++;
		}
		y++;
	}
}
