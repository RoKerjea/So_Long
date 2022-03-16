/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:23:40 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/14 17:23:42 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	makeassetarray(void **assets[6], t_libwin libwin)
{
	int	i;

	i = SQR;
	assets[0] = mlx_xpm_file_to_image(libwin.mlx, "assets/floor.xpm", &i, &i);
	assets[1] = mlx_xpm_file_to_image(libwin.mlx, "assets/wall.xpm", &i, &i);
	assets[2] = mlx_xpm_file_to_image(libwin.mlx, "assets/item.xpm", &i, &i);
	assets[3] = mlx_xpm_file_to_image(libwin.mlx, "assets/exit.xpm", &i, &i);
	assets[4] = mlx_xpm_file_to_image(libwin.mlx, "assets/start.xpm", &i, &i);
	assets[5] = mlx_xpm_file_to_image(libwin.mlx, "assets/chara.xpm", &i, &i);
}

void	writespritetosquare(void **assets[6], t_libwin libwin, int y, int x)
{
	if (libwin.mapdata.map[y][x] == '0')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, assets[0], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == '1')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, assets[1], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == 'C')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, assets[2], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == 'E')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, assets[3], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == 'P')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, assets[4], x * SQR, y * SQR);
}

int	makeimg(t_libwin *libwin)
{
	int		x;
	int		y;
	void	**assets[6];

	y = 0;
	makeassetarray(assets, *libwin);
	while (libwin->mapdata.map[y])
	{
		x = 0;
		while (libwin->mapdata.map[y][x])
		{
			writespritetosquare(assets, *libwin, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	wincloser(t_libwin *libwin)
{
	mlx_destroy_window(libwin->mlx, libwin->win);
	exit(0);
}

/*
void	printmapshell(t_mapdata mapdata)
{
	int	i = 0;

	printf("map received is \n");
	while (mapdata.map[i])
	{
		printf("%s\n", mapdata.map[i]);
		i++;
	}
	printf("map length is %i\n", mapdata.length);
	printf("map height is %i\n", mapdata.height);
	printf("map number of items is %i\n", mapdata.itemcount);
	printf("starting position is x = %i and y = %i\n", mapdata.pos[1], mapdata.pos[0]);
	printf("number of move done is %i\n", mapdata.movcount);
}*/

int	main(int argc, char **argv)
{
	t_libwin	libwin;

	libwin.mapdata.map = map_parser(argc, argv);
	if (libwin.mapdata.map == NULL)
		exit(0);
	getmapinfo(&libwin.mapdata);
	//printmapshell(libwin.mapdata);
	libwin.mlx = mlx_init();
	libwin.win = mlx_new_window(libwin.mlx, libwin.mapdata.length * SQR,
			libwin.mapdata.height * SQR, "...and thanks for the fishes!");
	makeimg(&libwin);
	mlx_hook(libwin.win, 2, 1L << 0, keyparser, &libwin);
	mlx_hook(libwin.win, 17, 1L << 2, wincloser, &libwin);
	mlx_loop_hook(libwin.mlx, makeimg, &libwin);
	mlx_loop(libwin.mlx);
}
