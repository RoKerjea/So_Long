/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmapshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:06:07 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/18 22:06:10 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	printmapshell(t_mapdata mapdata)
{
	int	i;

	i = 0;
	printf("map received is \n");
	while (mapdata.map[i])
	{
		printf("%s\n", mapdata.map[i]);
		i++;
	}
	i = 0;
	printf("previous map was \n");
	while (mapdata.prevmap[i])
	{
		printf("%s\n", mapdata.prevmap[i]);
		i++;
	}
	printf("map length is %i\n", mapdata.length);
	printf("map height is %i\n", mapdata.height);
	printf("map number of items is %i\n", mapdata.itemcount);
	printf("player position is  x = %i and y = %i\n",
		mapdata.pos[1], mapdata.pos[0]);
	printf("number of move done is %i\n", mapdata.movcount);
}
