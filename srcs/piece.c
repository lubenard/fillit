/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 14:59:51 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/20 17:05:23 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place(t_tetri *t, char **map, t_coord pmap)
{
	int		prob;
	int		k;

	k = 0;
	prob = 0;
	if (map[t->c[k].y + pmap.y][t->c[k].x + pmap.x] == '.')
		map[t->c[k].y + pmap.y][t->c[k].x + pmap.x] = t->letter;
	else
		prob = 1;
	if (prob == 1)
		return (-1);
	return (0);
}