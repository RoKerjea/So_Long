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

int	printmovement(t_libwin *libwin)
{
	write (1, "You moved ", 10);
	ft_putnbr (libwin->mapdata.movcount);
	write (1, " times\n", 7);
	return (0);
}

void	gameover(t_libwin *libwin)
{
	write (1, "Congratulations!\nYou finished the map in ", 41);
	ft_putnbr (libwin->mapdata.movcount + 1);
	write (1, " moves!\n", 8);
	wincloser(libwin);
}

void	copymaptab(t_libwin *libwin)
{
	int	y;
	int	x;

	y = 0;
	while (libwin->mapdata.map[y])
	{
		x = 0;
		while (libwin->mapdata.map[y][x])
		{
			libwin->mapdata.prevmap[y][x] = libwin->mapdata.map[y][x];
			x++;
		}
		y++;
	}
}

int	move(t_libwin *libwin, int pos[2], int ny, int nx)
{
	if ((libwin->mapdata.map[ny][nx] == 'E'
		&& libwin->mapdata.itemcount > 0) || libwin->mapdata.map[ny][nx] == '1')
		return (0);
	else if (libwin->mapdata.map[ny][nx] == 'E'
		&& libwin->mapdata.itemcount == 0)
		gameover(libwin);
	copymaptab(libwin);
	if (libwin->mapdata.map[ny][nx] == '0'
		|| libwin->mapdata.map[ny][nx] == 'P')
	{
		libwin->mapdata.map[ny][nx] = 'P';
		libwin->mapdata.map[pos[0]][pos[1]] = '0';
	}
	if (libwin->mapdata.map[ny][nx] == 'C')
	{
		libwin->mapdata.map[ny][nx] = 'P';
		libwin->mapdata.map[pos[0]][pos[1]] = '0';
		libwin->mapdata.itemcount--;
	}
	libwin->mapdata.movcount++;
	makeimg(libwin);
	printmovement(libwin);
	libwin->mapdata.pos[0] = ny;
	libwin->mapdata.pos[1] = nx;
	return (1);
}

int	keyparser(int keycode, t_libwin *libwin)
{
	int	pos[2];

	pos[0] = libwin->mapdata.pos[0];
	pos[1] = libwin->mapdata.pos[1];
	if (keycode == 119)
		move(libwin, pos, pos[0] - 1, pos[1]);
	if (keycode == 115)
		move(libwin, pos, pos[0] + 1, pos[1]);
	if (keycode == 97)
		move(libwin, pos, pos[0], pos[1] - 1);
	if (keycode == 100)
		move(libwin, pos, pos[0], pos[1] + 1);
	if (keycode == 65307)
		wincloser(libwin);
	return (0);
}

/*
int	keyparser(int keycode, t_libwin *libwin)
{
	int	pos[2];

	pos[0] = libwin->mapdata.pos[0];
	pos[1] = libwin->mapdata.pos[1];
	if (keycode == 13)
		move(libwin, pos, pos[0] - 1, pos[1]);
	if (keycode == 1)
		move(libwin, pos, pos[0] + 1, pos[1]);
	if (keycode == 0)
		move(libwin, pos, pos[0], pos[1] - 1);
	if (keycode == 2)
		move(libwin, pos, pos[0], pos[1] + 1);
	if (keycode == 53)
		wincloser(libwin);
	return (0);
}*/
