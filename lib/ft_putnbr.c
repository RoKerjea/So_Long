/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokerjea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:16:01 by rokerjea          #+#    #+#             */
/*   Updated: 2022/03/18 22:16:06 by rokerjea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putnbr(unsigned int i)
{
	char	c;

	if (i > 9)
		ft_putnbr(i / 10);
	c = (i % 10) + '0';
	write (1, &c, 1);
	return (0);
}
