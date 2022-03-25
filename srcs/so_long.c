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

int	makeassetarray(t_libwin *libwin)
{
	int i;

	i = 0;
	while (i < 5)
	{
		libwin->img[i] = NULL;
		i++;
	}
	i = SQR;
	libwin->img[0] = mlx_xpm_file_to_image(libwin->mlx, "./img/soil.xpm", &i, &i);
	libwin->img[1] = mlx_xpm_file_to_image(libwin->mlx, "./img/wall.xpm", &i, &i);
	libwin->img[2] = mlx_xpm_file_to_image(libwin->mlx, "./img/item.xpm", &i, &i);
	libwin->img[3] = mlx_xpm_file_to_image(libwin->mlx, "./img/exit.xpm", &i, &i);
	libwin->img[4] = mlx_xpm_file_to_image(libwin->mlx, "./img/char.xpm", &i, &i);
	if (libwin->img[0] == NULL || libwin->img[1] == NULL
		|| libwin->img[2] == NULL || libwin->img[3] == NULL
		|| libwin->img[4] == NULL)
		{
			return (0);
		}
	return (1);
}

void	writespritetosquare(t_libwin libwin, int y, int x)
{
	if (libwin.mapdata.map[y][x] == '0')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, libwin.img[0], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == '1')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, libwin.img[1], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == 'C')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, libwin.img[2], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == 'E')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, libwin.img[3], x * SQR, y * SQR);
	if (libwin.mapdata.map[y][x] == 'P')
		mlx_put_image_to_window(libwin.mlx,
			libwin.win, libwin.img[4], x * SQR, y * SQR);
}

int	makeimg(t_libwin *libwin)
{
	int		x;
	int		y;

	y = 0;
	while (libwin->mapdata.map[y])
	{
		x = 0;
		while (libwin->mapdata.map[y][x])
		{
			if (libwin->mapdata.map[y][x] != libwin->mapdata.prevmap[y][x])
			{
				//printf("reecriture du carre %i %i de l\'image\n", y, x);
				writespritetosquare(*libwin, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	argcheck(int argc, char **argv)
{
	int	testfd;

	if (argc != 2)
	{
		write (1, "Error\nProgram need 1 argument\n", 30);
		return (0);
	}
	if (ft_strendcomp(argv[1], ".ber"))
	{
		write (1, "Error\nWrong file as argument\n", 29);
		return (0);
	}
	testfd = open(argv[1], O_DIRECTORY);
	if (testfd > 0)
	{
		write (1, "Error\nargument is a directory\n", 30);
		return (0);
	}
	close(testfd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_libwin	libwin;
	char		*linecpy;
	
	if (!argcheck(argc, argv))
		return (0);
	libwin.mapdata.map = map_parser(argv);
	linecpy = cpymap(libwin.mapdata.map);
	libwin.mapdata.prevmap = ft_split(linecpy, '\n');
	free(linecpy);
	if (libwin.mapdata.map == NULL || libwin.mapdata.prevmap == NULL)
		return (0);
	getmapinfo(&libwin.mapdata);
	libwin.mlx = mlx_init();
	if (makeassetarray(&libwin) == 0)
	{
		printf("ceci est un probleme mais gerer corrctement pour le moment\n");
		wincloser(&libwin);
	}
	libwin.win = mlx_new_window(libwin.mlx, libwin.mapdata.length * SQR,
			libwin.mapdata.height * SQR, "...and thanks for the fishes!");
	//printmapshell(libwin.mapdata);
	makeimg(&libwin);
	mlx_hook(libwin.win, 2, 1L << 0, keyparser, &libwin);
	mlx_hook(libwin.win, 17, 1L << 2, wincloser, &libwin);
	mlx_loop(libwin.mlx);
}
