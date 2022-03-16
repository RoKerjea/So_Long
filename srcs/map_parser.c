/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:44:24 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/16 14:44:33 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**readmap(int fd)
{
	char	*mapline;
	char	*tmp;
	int		count;
	char	*buffer;

	tmp = NULL;
	mapline = "\n";
	count = 1;
	buffer = (char *)malloc(sizeof(char) * 101);
	while (count > 0)
	{
		count = read(fd, buffer, 100);
		buffer[count] = '\0';
		tmp = ft_strjoin(mapline, buffer);
		if (!tmp)
			return (NULL);
		mapline = tmp;
	}
	free (buffer);
	return (ft_split(mapline, '\n'));
}

int	mapwalled(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[0][x])
	{
		if (map[0][x] != '1')
			return (0);
		x++;
	}
	while (map[y])
	{
		if (map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (map[y - 1][x])
	{
		if (map[y - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	mapcontent(char **map)
{
	int	y;
	int	cep[3];

	cep[0] = 0;
	cep[1] = 0;
	cep[2] = 0;
	y = 0;
	while (map[y])
	{
		if (ft_strchr(map[y], 'C') != 0)
			cep[0]++;
		if (ft_strchr(map[y], 'E') != 0)
			cep[1]++;
		if (ft_strchr(map[y], 'P') != 0)
			cep[2]++;
		y++;
	}
	if (cep[0] == 0 || cep[1] == 0 | cep[2] == 0)
	{
		write (1, "Error\nMap is missing necessary content\n", 39);
		return (0);
	}
	return (1);
}

int	mapchecker(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		if (strlen(map[y]) != strlen(map[0]))
		{
			write (1, "Error\nMap isn't rectangular\n", 28);
			return (0);
		}
		y++;
	}
	if (mapwalled(map) == 0)
	{
		write (1, "Error\nMap isn't fully enclosed by walls\n", 40);
		return (0);
	}
	if (mapcontent(map) == 0)
		return (0);
	return (1);
}

char	**map_parser(int argc, char **argv)
{
	int		mapfd;
	char	**map;

	if (argc != 2)
	{
		write (1, "Error\nProgram need 1 argument\n", 30);
		return (NULL);
	}
	if (ft_strendcomp(argv[1], ".ber"))
	{
		write (1, "Error\nWrong file as argument\n", 29);
		return (NULL);
	}
	if (open(argv[1], O_DIRECTORY) > 0)
	{
		write (1, "Error\nargument is a directory\n", 30);
		return (NULL);
	}
	mapfd = open(argv[1], O_RDONLY);
	if (mapfd < 0)
	{
		write (1, "Error\ncan't open map file\n", 26);
		return (NULL);
	}
	map = readmap(mapfd);
	if (!map)
		return (NULL);
	if (mapchecker(map) == 1)
		return (map);
	free (map);
	return (0);
}
