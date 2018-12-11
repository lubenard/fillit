/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:01:32 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/11 18:04:14 by lubenard         ###   ########.fr       */
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
	int			e;

	i = 0;
	e = 0;
	lkd_list = new_tetrimino();
	while (str[i] != '\n')
			i++;
	printf("i = %d\n", i);
	lkd_list->firstline = ft_strsub(str, e, i);
	i++;
	e = i;
	printf("e = %d = %c\n", e, str[e]);
	while (str[i] != '\n')
			i++;
	printf("i = %d\n", i);
	lkd_list->secondline = ft_strsub(str, e, i);
	i++;
	e = i;
	printf("e = %d = %c\n", e, str[e]);
	while(str[i] != '\n')
		i++;
	printf("i = %d\n", i);
	lkd_list->thirdline = ft_strsub(str, e, i);
	i++;
	e = i;
	printf("e = %d = %c\n", e, str[e]);
	while(str[i] != '\n')
		i++;
	lkd_list->lastline = ft_strsub(str, e, i);

		printf("firstline: %s\nSecond Line: %s\nThirdLine: %s\nLastLine: %s\n", lkd_list->firstline, lkd_list->secondline, \
				lkd_list->thirdline, lkd_list->lastline);
}
