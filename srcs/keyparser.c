/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:02:24 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/16 20:02:27 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int moveup(t_libwin *libwin)
{
	int	y;
	int	x;

	y = libwin->mapdata.pos[0];
	x = libwin->mapdata.pos[1];
	if (libwin->mapdata.map[y - 1][x] == '1')
		return (0);
	if (libwin->mapdata.map[y - 1][x] == '0')
	{
		libwin->mapdata.map[y - 1][x] = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
	}
	if (libwin->mapdata.map[y - 1][x] == 'C')
	{
		libwin->mapdata.map[y - 1][x] = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
		libwin->mapdata.itemcount--;
	}
	if (libwin->mapdata.map[y - 1][x] == 'E')
	{
		libwin->mapdata.map[y - 1][x] = 'P';
		libwin->mapdata.map[y][x] = '0';
		if (libwin->mapdata.itemcount == 0)
			wincloser(libwin);
	}
	libwin->mapdata.pos[0] = y - 1;
	libwin->mapdata.pos[1] = x;
	return (1);
}

int movedown(t_libwin *libwin)
{
	int	y;
	int	x;

	y = libwin->mapdata.pos[0];
	x = libwin->mapdata.pos[1];
	if (libwin->mapdata.map[y + 1][x] == '1')
		return (0);
	if (libwin->mapdata.map[y + 1][x] == '0')
	{
		libwin->mapdata.map[y + 1][x] = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
	}
	if (libwin->mapdata.map[y + 1][x] == 'C')
	{
		libwin->mapdata.map[y + 1][x] = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
		libwin->mapdata.itemcount--;
	}
	if (libwin->mapdata.map[y + 1][x] == 'E')
	{
		libwin->mapdata.map[y + 1][x] = 'P';
		libwin->mapdata.map[y][x] = '0';
		if (libwin->mapdata.itemcount == 0)
			wincloser(libwin);
	}
	libwin->mapdata.pos[0] = y + 1;
	libwin->mapdata.pos[1] = x;
	return (1);
}

int moveleft(t_libwin *libwin)
{
	int	y;
	int	x;

	y = libwin->mapdata.pos[0];
	x = libwin->mapdata.pos[1];
	if (libwin->mapdata.map[y][x - 1] == '1')
		return (0);
	if (libwin->mapdata.map[y][x - 1] == '0')
	{
		libwin->mapdata.map[y][x - 1] = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
	}
	if (libwin->mapdata.map[y][x - 1] == 'C')
	{
		libwin->mapdata.map[y][x - 1]  = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
		libwin->mapdata.itemcount--;
	}
	if (libwin->mapdata.map[y][x - 1] == 'E')
	{
		libwin->mapdata.map[y][x - 1]  = 'P';
		libwin->mapdata.map[y][x] = '0';
		if (libwin->mapdata.itemcount == 0)
			wincloser(libwin);
	}
	libwin->mapdata.pos[0] = y;
	libwin->mapdata.pos[1] = x - 1;
	return (1);
}

int moveright(t_libwin *libwin)
{
	int	y;
	int	x;

	y = libwin->mapdata.pos[0];
	x = libwin->mapdata.pos[1];
	if (libwin->mapdata.map[y][x + 1] == '1')
		return (0);
	if (libwin->mapdata.map[y][x + 1] == '0')
	{
		libwin->mapdata.map[y][x + 1] = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
	}
	if (libwin->mapdata.map[y][x + 1] == 'C')
	{
		libwin->mapdata.map[y][x + 1]  = 'P';
		libwin->mapdata.map[y][x] = '0';
		libwin->mapdata.movcount++;
		libwin->mapdata.itemcount--;
	}
	if (libwin->mapdata.map[y][x - 1] == 'E')
	{
		libwin->mapdata.map[y][x + 1]  = 'P';
		libwin->mapdata.map[y][x] = '0';
		if (libwin->mapdata.itemcount == 0)
			wincloser(libwin);
	}
	libwin->mapdata.pos[0] = y;
	libwin->mapdata.pos[1] = x + 1;
	return (1);
}

int	keyparser(int keycode, t_libwin *libwin)
{
	printf("keycode pressed is %i in int\n", keycode);
	if (keycode == 13)
		moveup(libwin);
	if (keycode == 1)
		movedown(libwin);
	if (keycode == 0)
		moveleft(libwin);
	if (keycode == 2)
		moveright(libwin);
	if (keycode == 53)
		wincloser(libwin);
	printmapshell(libwin->mapdata);
	return (0);
}