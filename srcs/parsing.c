/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:01:32 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/20 16:38:13 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*new_tetrimino(void)
{
	t_tetri		*list;

	if (!(list = (t_tetri *)malloc(sizeof(*list))))
		return (0);
	if (!(list->tetrimino = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[0] = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[1] = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[2] = malloc(sizeof(char) * 4)) || \
		!(list->tetrimino[3] = malloc(sizeof(char) * 4)))
		return (NULL);
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

char		putletter(void)
{
	static char letter = 'A';

	return (letter++);
}

int			compute(t_tetri *lkd_list, t_tetri *new_element, int i, char *str)
{
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
			return (-1);
		optimize_tetri(lkd_list->tetrimino);
		make_coord_p(lkd_list);
		lkd_list->letter = putletter();
		if (str[i - 1] != '\0')
		{
			if (!(new_element = new_tetrimino()))
				return (-1);
			lkd_list->next = new_element;
			lkd_list->next->prev = lkd_list;
			lkd_list = new_element;
		}
	}
	return (0);
}

t_tetri		*parsing(char *str)
{
	t_tetri		*lkd_list;
	t_tetri		*new_element;
	t_tetri		*first_element;
	int			i;

	i = 0;
	new_element = NULL;
	if (!(lkd_list = new_tetrimino()))
		return (NULL);
	first_element = lkd_list;
	if (compute(lkd_list, new_element, i, str) == -1)
		return (NULL);
	return (first_element);
}
