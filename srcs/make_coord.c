/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:53:40 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/19 14:26:37 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*make_coord_one(t_tetri *t)
{
	char **tab;
	int		i;
	int		j;
	int		b;

	tab = t->tetrimino;
	b = 1;
	j = 0;
	while(j != 4)
	{
		i = 0;
		while (i != 4)
		{
			if (tab[j][i] == '#')
			{
				if (b == 1)
				{
					t->c1.x = i + 1;
					t->c1.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b == 2)
				{
					t->c2.x = i + 1;
					t->c2.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b == 3)
				{
					t->c3.x = i + 1;
					t->c3.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b == 4)
				{
					t->c4.x = i + 1;
					t->c4.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b > 4)
					ft_putstr("IMPOSSIBLE MERDE");
			}
			i++;
		}
		j++;
	}
	t->pos.x = 0;
	t->pos.y = 0;
	return (t);
}

t_tetri		*make_coord(t_tetri *t)
{
	while (t->next != NULL)
	{
		t = make_coord_one(t);
		t = t->next;
	}
	t = make_coord_one(t);
	while (t->prev != NULL)
		t = t->prev;
	return(t);
}

void		*make_coord_p(t_tetri *t)
{
	char **tab;
	int		i;
	int		j;
	int		b;

	tab = t->tetrimino;
	b = 1;
	j = 0;
	while(j != 4)
	{
		i = 0;
		while (i != 4)
		{
			if (tab[j][i] == '#')
			{
				if (b == 1)
				{
					t->c1.x = i + 1;
					t->c1.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b == 2)
				{
					t->c2.x = i + 1;
					t->c2.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b == 3)
				{
					t->c3.x = i + 1;
					t->c3.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b == 4)
				{
					t->c4.x = i + 1;
					t->c4.y = j + 1;
					b++;
					i++;
					continue ;
				}
				if (b > 4)
					ft_putstr("IMPOSSIBLE MERDE");
			}
			i++;
		}
		j++;
	}
	t->pos.x = 0;
	t->pos.y = 0;
	return (t);
}
