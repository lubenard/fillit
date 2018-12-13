/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:01:32 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/13 15:21:48 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

t_tetrimino		*new_tetrimino(void)
{
	t_tetrimino		*list;

	if (!(list = (t_tetrimino *)malloc(sizeof(*list))))
		return (0);
	if (!(list->tetrimino = malloc(sizeof(char) * 5)) || \
		!(list->tetrimino[0] = malloc(sizeof(char) * 5)) || \
		!(list->tetrimino[1] = malloc(sizeof(char) * 5)) || \
		!(list->tetrimino[2] = malloc(sizeof(char) * 5)) || \
		!(list->tetrimino[3] = malloc(sizeof(char) * 5 )))
		return (NULL);
	list->tetrimino[0][5] = '\0';
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

void			parsing(char *str)
{
	t_tetrimino	*lkd_list;
	t_tetrimino	*test;
	int			i;

	lkd_list = new_tetrimino();
	i = 0;
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
		printf("%s\n%s\n%s\n%s\n\n", lkd_list->tetrimino[0], lkd_list->tetrimino[1], lkd_list->tetrimino[2], lkd_list->tetrimino[3]);
		test = new_tetrimino();
		lkd_list->next = test;
		lkd_list = test;
	}
}
