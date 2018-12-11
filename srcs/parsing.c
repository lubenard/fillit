/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:01:32 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/11 16:19:54 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

t_triomino		*new_tetrimino(void)
{
	t_triomino	*list;

	if (!(list = (t_triomino *)malloc(sizeof(*list))))
		return (0);
	if (!(list->firstline = malloc(sizeof(char) * 5)) || \
		!(list->secondline = malloc(sizeof(char) * 5)) || \
		!(list->thirdline = malloc(sizeof(char) * 5)) || \
		!(list->lastline = malloc(sizeof(char) * 5)))
		return (NULL);
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

void			parsing(char *str)
{
	t_triomino	*lkd_list;
	int			i;
	int			fl;
	int			sl;
	int			td;
	int			ll;

	i = 0;
	lkd_list = new_tetrimino();
	while (str[i])
	{
		while (str[i] != '\n')
			i++;
		lkd_list->firstline = ft_strsub(str, 0, i);
		printf("First line =  %s\n", lkd_list->firstline);
	}
}
