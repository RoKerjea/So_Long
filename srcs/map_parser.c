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

int	checkmapline(char *line)
{
	int	i;
	int	cep[3];

	cep[0] = 0;
	cep[1] = 0;
	cep[2] = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			cep[0]++;
		if (line[i] == 'E')
			cep[1]++;
		if (line[i] == 'P')
			cep[2]++;
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != '\n')
			return (write (1, "Error\nMap contain unknown character\n", 36));
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (write (1, "Error\nNewline in map x2\n", 24));
		i++;
	}
	if (cep[0] == 0 || cep[1] == 0 || cep[2] == 0)
		return (write (1, "Error\nMap is missing necessary element\n", 39));
	return (1);
}

char	*readmap(int fd)
{
	char	*mapline;
	char	*tmp;
	int		count;
	char	*buffer;

	tmp = NULL;
	mapline = "\n";
	count = 1;
	buffer = (char *)malloc(sizeof(char) * 101);
	if (!buffer)
		return (NULL);
	while (count > 0)
	{
		count = read(fd, buffer, 100);
		buffer[count] = '\0';
		tmp = ft_strjoin(mapline, buffer);
		if (ft_strlen(mapline) > 1)
			free(mapline);
		if (!tmp)
			return (NULL);
		mapline = ft_strdup(tmp);
		free(tmp);
	}
	free (buffer);
	return (mapline);
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

int	mapchecker(char **map)
{
	int	y;

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
	return (1);
}

char	**map_parser(char **argv)
{
	int		mapfd;
	char	**map;
	char	*mapline;

	mapfd = open(argv[1], O_RDONLY);
	if (mapfd < 0)
	{
		write (1, "Error\nCan't open map file\n", 26);
		return (NULL);
	}
	mapline = readmap(mapfd);
	close (mapfd);
	if (checkmapline(mapline) != 1)
		free(mapline);
	if (!mapline || mapline == NULL)
		return (NULL);
	map = ft_split(mapline, '\n');
	free (mapline);
	if (!map)
		return (NULL);
	if (mapchecker(map) == 1)
		return (map);
	ft_freetab (map);
	return (NULL);
}
