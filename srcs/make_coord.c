/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:53:40 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/20 17:10:43 by jmoussu          ###   ########.fr       */
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
	if (k == 4)
		return (t);
	else
	{
		ft_putstr("HO MY FUCKING BITCHIZ SO HOT");
		return(NULL);
	}
}


// void		*make_coord_p(t_tetri *t)
// {
// 	char	**tab;
// 	int		i;
// 	int		j;
// 	int		b;

// 	tab = t->tetrimino;
// 	b = 1;
// 	j = 0;
// 	while (j != 4)
// 	{
// 		i = 0;
// 		while (i != 4)
// 		{
// 			if (tab[j][i] == '#')
// 			{
// 				if (b == 1)
// 				{
// 					t->c1.x = i;
// 					t->c1.y = j;
// 					b++;
// 					i++;
// 					continue ;
// 				}
// 				if (b == 2)
// 				{
// 					t->c2.x = i;
// 					t->c2.y = j;
// 					b++;
// 					i++;
// 					continue ;
// 				}
// 				if (b == 3)
// 				{
// 					t->c3.x = i;
// 					t->c3.y = j;
// 					b++;
// 					i++;
// 					continue ;
// 				}
// 				if (b == 4)
// 				{
// 					t->c4.x = i;
// 					t->c4.y = j;
// 					b++;
// 					i++;
// 					continue ;
// 				}
// 				if (b > 4)
// 					ft_putstr("IMPOSSIBLE MERDE");
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	t->pos.x = -1;
// 	t->pos.y = -1;
// 	return (t);
// }
