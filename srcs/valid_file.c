/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:25 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/14 13:49:56 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		check4x4(char *str)
{
	int		i;
	int		j;
	char	*ptr;

	ptr = str;
	j = 0;
	i = 0;
	if (ptr[0] == 0)
		return (-1);
	while (ptr[i] != 0)
	{
		i = 0;
		while (ptr[i] != '\n' && j < 4)
		{
			if (i >= 4)
				return (-1);
			i++;
		}
		if (i != 4)
			return (-1);
		ptr = ptr + i + 1; // ?? Ne pas deplacer les pointeurs, c'est MAL
		if (j < 4)
		{
			if (ptr[i] != '.' || ptr[i] != '#')
			{
				ft_putstr("Prob de signe, signe diff de '.' ou de '#'\n");
				return (-1);
			}
			j++;
		}
		else if (j == 4)
		{
			if (ptr[0] != '\n')
				return (-1);
			ptr++;
			j = 0;
		}
	}
	return (0);
}

int		valid_file(char *str)
{
	if (check4x4(str))
	{
		ft_putstr("Not a valid file fuck\n");
		return (-1);
	}
	return (0);
}

/*
** Verifier les fichier avant le parsing
**
** Commence par une ligne de 4 char + \n
**
** Verifier que c'est des block de 4 ligne séparer par une ligne \n
**
** Verifier que c'est que des . et # dans les block
**
** verifier que il y a pas plus de 26 tétriminos donc 129 ligne max
** (26 * 4)tetriminos + 25 ligne de séparation
*/
