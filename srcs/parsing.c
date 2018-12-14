/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:01:32 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/14 22:14:54 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

t_tetrimino		*new_tetrimino(void)
{
	t_tetrimino		*list;

	if (!(list = (t_tetrimino *)malloc(sizeof(*list))))
		return (0);
	if (!(list->tetrimino = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[0] = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[1] = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[2] = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[3] = malloc(sizeof(char) * 4)))
		return (NULL);
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

int				verif_tetrimino(char **str)
{
	int i;
	int compteur;
	int e;

	e = 0;
	i = 0;
	compteur = 0;
	while (i < 4)
	{
		while (e < 4)
		{
			if (str[i][e] == '#')
				compteur++;
			e++;
		}
		i++;
		e = 0;
		if (compteur != 4)
			return (-1);
	}
	return (0);
}

t_tetrimino		*parsing(char *str)
{
	t_tetrimino	*lkd_list;
	t_tetrimino	*new_element;
	t_tetrimino	*first_element;
	int			i;

	i = 0;
	if (!(lkd_list = new_tetrimino()))
		return (NULL);
	first_element = lkd_list;
	while (str[i])
	{
		lkd_list->tetrimino[0] = ft_strsub(str, i, 4);
		while (str[i] != '\n')
			i++;
		lkd_list->tetrimino[1] = ft_strsub(str, ++i, 4);
		while (str[i] != '\n')
			i++;
		lkd_list->tetrimino[2] = ft_strsub(str, ++i, 4);
		while (str[i] != '\n')
			i++;
		lkd_list->tetrimino[3] = ft_strsub(str, ++i, 4);
		while (str[i] != '\n')
			i++;
		i += 2;
		if (verif_tetrimino(lkd_list->tetrimino) == -1)
			return (NULL);
		if (!(new_element = new_tetrimino()))
			return (NULL);
		lkd_list->next = new_element;
		lkd_list = new_element;
	}
	printf("Well it run cool !\n");
	return (first_element);
}
