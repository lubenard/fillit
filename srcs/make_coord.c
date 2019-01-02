/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:53:40 by jmoussu           #+#    #+#             */
/*   Updated: 2019/01/02 15:08:52 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*make_coord_p(t_tetri *t)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = t->tetrimino;
	k = 0;
	j = 0;
	while (j != 4)
	{
		i = 0;
		while (i != 4)
		{
			if (tab[j][i] == '#')
			{
				t->c[k].x = i;
				t->c[k].y = j;
				k++;
			}
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
