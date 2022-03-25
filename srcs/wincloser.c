/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wincloser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:46:27 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/18 22:46:29 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	while (i >= 0)
	{
		if (tab[i])
			free(tab[i]);
		i--;
	}
	free(tab);
}

int	wincloser(t_libwin *libwin)
{
	if (libwin->mapdata.map)
	{
		printf("freeing libwin->mapdata.map\n");
		ft_freetab(libwin->mapdata.map);
	}
	if (libwin->mapdata.prevmap)
	{
		printf("freeing libwin->mapdata.prevmap\n");
		ft_freetab(libwin->mapdata.prevmap);
	}
	int i = 0;
	while (i < 5)
	{
		if (libwin->img[i])
		{
			printf("destroying img = %d\n", i);
			mlx_destroy_image(libwin->mlx, libwin->img[i]);
		}
		i++;
	}
	if (libwin->win)
		mlx_destroy_window(libwin->mlx, libwin->win);
	mlx_destroy_display(libwin->mlx);
	free(libwin->mlx);
	exit(0);
}
