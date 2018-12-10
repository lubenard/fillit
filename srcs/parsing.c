/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:01:32 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/10 14:24:37 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void	parsing(char *str)
{
	t_triomino	*lkd_list;
	int			i;

	i = 0;
	lkd_list = NULL;
	while (str[i] != '\n')
		i++;
	//if (!(lkd_list->firstline = (char *)malloc(sizeof(char) * 5)))
	//	return ;
		//lkd_list->firstline = ft_strsub(str, 0, i);
		//--> Les trois lignes du dessus segfaut mais je sais pas pq, bonne chance pour trouver, ca n'a aucun sens
}
