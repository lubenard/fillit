/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:59:54 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/02 15:14:12 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Mission 0 crée la map et l'afficher avec des point !
**
** Mission 1 Placer 1 tériminos dans la map et l'afficher a la bonne taille
**		besoin de recupere les coordone des 4 block
** MISSION 2 REFAIRE MISSION 1 AVEC LA NOUVELLE STRUCTURE
**
** MISSION 3 BACKTRAKING 2 PIECE L relou et Z relou
*/

/*
** Mission 3
** Crée une fonction pour placer retirer
** si pos.x et pos.y == size ini map size++;
*/

char	**solve(t_tetri *t)
{
	char	**map;
	int		size;
	t_coord	pmap;

	size = 2;
	map = ini_map(size, 90); // free map ou leaks
	ici:
	while (1)
	{
		if (t->pos.y == -1)
			pmap.y = 0; // 0 si pos = -1 sinon recuperer pos je supose
		else
		{
			pmap.y = t->pos.y;
		}
		while (pmap.y != size)
		{
			if (t->pos.x == -1)
				pmap.x = 0;
			else
			{
				pmap.x = t->pos.x + 1;
				t->pos.x = -1;
			}
			while (pmap.x != size)
			{
				if (!(place(t, map, pmap)))
				{
					if (t->next == NULL)
						return (map);
					else
					{
						t = t->next;
						goto ici;
					}
				}
				pmap.x++;
			}
			pmap.x = -1;
			pmap.y++;
		}
		if (t->letter == 'A' && t->prev == NULL)
		{
			t->pos.y = -1; // mettre dans remove_end meme  si erreur
			t->pos.x = -1;
			map = ini_map(++size, 90); // free map ou leaks
			continue ;
		}
		else if (t->letter != 'A' && t->prev != NULL)
		{
			t->pos.y = -1; // mettre dans remove_end meme  si erreur
			t->pos.x = -1;
			t = t->prev;
	}
		else
			ft_putstr("Wtf\n");
	}
	ft_putstr("Fin de solve anormal\n");
	return (map);
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
