/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 17:22:41 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/14 17:22:46 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define SQR 64

typedef struct s_mapdata
{
	char				**map;
	char				**prevmap;
	unsigned int		movcount;
	unsigned int		itemcount;
	int					pos[2];
	int					length;
	int					height;
}				t_mapdata;

typedef struct s_libwin
{
	void				*mlx;
	void				*win;
	void				**img[5];
	struct s_mapdata	mapdata;
}				t_libwin;

char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
char			**map_parser(char **argv);
void			getmapinfo(t_mapdata *mapdata);
int				keyparser(int keycode, t_libwin *libwin);
int				wincloser(t_libwin *libwin);
void			printmapshell(t_mapdata mapdata);
int				ft_strchr(const char *s, int c);
unsigned long	ft_strlen(const char *s);
int				ft_strendcomp(const char *s1, const char *s2);
int				makeimg(t_libwin *libwin);
int				ft_putnbr(unsigned int i);
char			*cpymap(char **tab);

//only for tests! delete later!
void			printmapshell(t_mapdata mapdata);

#endif
