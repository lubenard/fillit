/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:53:40 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/09 11:23:26 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			compute_make_coord_p(t_tetri *t, int i, int j, int k)
{
	if (t->tetrimino[j][i] == '#')
	{
		t->c[k].x = i;
		t->c[k].y = j;
		k++;
	}
	return (k);
}

t_tetri		*make_coord_p(t_tetri *t)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	while (j != 4)
	{
		i = 0;
		while (i != 4)
		{
			k = compute_make_coord_p(t, i, j, k);
			i++;
		}
		j++;
	}
	t->pos.x = -1;
	t->pos.y = -1;
	if (k == 4)
		return (t);
	else
		return (NULL);
}
