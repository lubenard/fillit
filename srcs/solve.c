/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:59:54 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/10 00:10:53 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compute_end(int *r, t_tetri **t, char ***m, int *s)
{
	int	i;

	i = 0;
	if (*r == 1)
	{
		*r = 0;
		return (1);
	}
	if ((*t)->letter == 'A' && (*t)->prev == NULL)
	{
		remove_end(*t, *m);
		while (i < 20)
			free((*m)[i++]);
		free(*m);
		i = 0;
		*m = ini_map(++(*s), 20);
		return (1);
	}
	if ((*t)->letter != 'A' && (*t)->prev != NULL)
	{
		remove_end(*t, *m);
		*t = (*t)->prev;
		remove_p(*t, *m);
	}
	return (0);
}

int		w(intptr_t *args, t_tetri **t, char ***m, t_coord *pm)
{
	while ((*pm).x != *((int *)args[1]))
	{
		if (!(place(*t, *m, *pm)))
		{
			if ((*t)->next == NULL)
				return (1);
			else
			{
				*t = (*t)->next;
				*((int *)args[0]) = 1;
				return (0);
			}
		}
		(*pm).x++;
	}
	return (0);
}

void	posx(t_tetri **t, t_coord *pm)
{
	if ((*t)->pos.x == -1)
		(*pm).x = 0;
	else
	{
		(*pm).x = (*t)->pos.x + 1;
		(*t)->pos.x = -1;
	}
}

char	**compute_solve(t_coord pm, t_tetri *t, char **m, int s)
{
	int r;

	r = 0;
	while (1)
	{
		if (t->pos.y == -1)
			pm.y = 0;
		else
			pm.y = t->pos.y;
		while (pm.y != s)
		{
			posx(&t, &pm);
			if (w((intptr_t[2]){(intptr_t)&r, (intptr_t)&s}, &t, &m, &pm) == 1)
				return (m);
			if (r == 1)
				break ;
			pm.x = -1;
			pm.y++;
		}
		if (compute_end(&r, &t, &m, &s) == 1)
			continue ;
	}
	return (NULL);
}

char	**solve(t_tetri *t)
{
	char	**m;
	int		s;
	t_coord	pm;
	char	**ret_val;

	s = 2;
	pm.x = 0;
	pm.y = 0;
	m = ini_map(s, 20);
	ret_val = compute_solve(pm, t, m, s);
	if (ret_val != NULL)
		return (ret_val);
	ft_putstr("Fin de solve anormal\n");
	return (m);
}

/*
** ------Back Tracking-----
**
** Comment crée la map ?
**		Commencer par une map grande !
**		C'est un tab[][]
**		Remplit avec des point pour indiquer qu'il est vide
**		On lui défini un max avec tous ce qui est au dessu du max est un \0
**
** On veux placer un téri comment verifier que l'on peut?
**		(on vérifie que le tériminos sort pas de la map !
**		-additions des coordonées tab et tétri et verif avec max)
**		On vérifie Qu'il y a des point la ou on veux placer le tériminos
**
** Comment placer les tétriminos ?
**		On place t1[0][0 dans map[0][0]
**		On remplace les # par ABC
**		Puis on place ABC a la place des point
**
** Que faire si ça fonctionne pas ?
**		On avance la pièce et on vérifie jusqua que l'on puisse la placer
**
** Que faire si la pièce peux pas être placer ? Elle est en max max !
**	Si c'est pas la pièce 1 :
**		On retire (place pas) la pièce x puis on avence la pièce x - 1
**		-jusqua quel puisse être placer si elle ne peut pas on continue
**		-avec la pièce x - 1 encore
**	Si c'est la pièce 1 qui est en max max ?
**		Il y a pas de soluce pour cette taille on fait max++
**		On recomence tout map reprend des . on ce replace au début
**
** Comment afficher la map ?
**		on affiche que de tab max en x et y
**
** OPTI compter le nombre total de block root(nombre de carrer)
*/
