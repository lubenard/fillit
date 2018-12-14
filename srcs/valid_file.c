/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:25 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/12 17:55:23 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check4x4(char *str)
{
	int i;
	int j;
	char *ptr;

	ptr = str;
	j = 0;
	i = 0;
	if (ptr[0] == 0)
		return (-1);
	while (ptr[i] != 0)
	{
		while (ptr[i] != '\n' && ptr[i] != '\0')
		{
			if (i >= 4)
			{
				ft_putstr("Ligne trop grande\n");
				return(-1);
			}
			i++;
		}
		if (i != 4 || ptr[i] == '\0')
			{
				ft_putstr("Ligne trop Petite\n");
				return(-1);
			}
		ptr = ptr + i + 1;
		ft_putstr("JUMP LINE\n");
		if (j < 3)
		{
			if (!(ptr[0] == '.' || ptr[0] == '#'))
			{
				ft_putstr("Il y pas le bon nombre de ligne\n");
				return(-1);
			}
			j++;
		}
		else if (j == 3)
		{
			ft_putstr("J est a 4\n");
			if (ptr[0] != '\n')
			{
				if (ptr[0] == '\0')
					return(0);
				ft_putstr("Tétrimino pas séparer par un backN\n");
				return (-1);
			}
			if (!(ptr[1] == '.' || ptr[1] == '#'))
			{
				return (-1);
			}
			ptr++;
			j = 0;
		}
		i = 0;
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