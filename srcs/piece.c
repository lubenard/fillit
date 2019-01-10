/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:59:51 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/10 10:29:18 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		canplace(t_tetri *t, char **map, t_coord pmap)
{
	int		prob;
	int		k;

	k = 0;
	prob = 0;
	while (k < 4)
	{
		if (map[t->c[k].y + pmap.y][t->c[k].x + pmap.x] == '.')
			k++;
		else
		{
			k++;
			prob = 1;
		}
	}
	if (prob == 1 || k != 4)
		return (-1);
	return (0);
}

int		placebrut(t_tetri *t, char **map, t_coord pmap)
{
	int		k;

	k = 0;
	while (k < 4)
	{
		map[t->c[k].y + pmap.y][t->c[k].x + pmap.x] = t->letter;
		k++;
	}
	return (0);
}

int		place(t_tetri *t, char **map, t_coord pmap)
{
	if (!(canplace(t, map, pmap)))
	{
		placebrut(t, map, pmap);
		t->pos = pmap;
	}
	else
		return (-1);
	return (0);
}

int		remove_end(t_tetri *t, char **map)
{
	int		k;

	k = 0;
	if (t->pos.x < 0 && t->pos.y < 0)
		return (-1);
	while (k < 4)
	{
		if (map[t->c[k].y + t->pos.y][t->c[k].x + t->pos.x] == t->letter)
			map[t->c[k].y + t->pos.y][t->c[k].x + t->pos.x] = '.';
		k++;
	}
	t->pos.x = -1;
	t->pos.y = -1;
	return (0);
}

int		remove_p(t_tetri *t, char **map)
{
	int		k;

	k = 0;
	if (t->pos.x < 0 || t->pos.y < 0)
		return (-1);
	while (k < 4)
	{
		if (map[t->c[k].y + t->pos.y][t->c[k].x + t->pos.x] == t->letter)
			map[t->c[k].y + t->pos.y][t->c[k].x + t->pos.x] = '.';
		k++;
	}
	return (0);
}
