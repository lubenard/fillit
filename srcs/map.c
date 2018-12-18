/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:59:54 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/17 17:08:45 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ini_map_cut(char **mapy, int *x, int size, int max)
{
	while (*x < max)
	{
		if (*x < size)
			(*mapy)[*x] = '.';
		else
			(*mapy)[*x] = '\0';
		(*x)++;
	}
}
/*
**
** max = size + 3 car un tétri va jamais dépasser de plus de 3 case sur le coté
*/
char	**ini_map(int size, int max)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	if (!(map = (char **)malloc(sizeof(char *) * max + 1)))
		return (NULL);
	while (y < max)
	{
		if (!(map[y] = (char *)malloc(sizeof(char) * max + 1)))
			return (NULL);
		x = 0;
		if (y < size)
			ini_map_cut(map + y, &x, size, max);
		else
		{
			while (x < max)
				map[y][x++] = '\0';
		}
		y++;
	}
	return (map);
}

void	display_map(char **map)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (map[y][x] != '\0')
	{
		while (map[y][x] != '\0')
		{
			ft_putchar(map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
		x = 0;
	}
}
