/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:01:25 by jmoussu           #+#    #+#             */
/*   Updated: 2018/12/21 10:08:02 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cut4x4(int *i, int *j, char **ptr)
{
	if (*j < 3)
	{
		if (!((*ptr)[0] == '.' || (*ptr)[0] == '#'))
			return (-1);
		(*j)++;
	}
	else if (*j == 3)
	{
		if ((*ptr)[0] != '\n')
		{
			if ((*ptr)[0] == '\0')
				return (0);
			return (-1);
		}
		if (!((*ptr)[1] == '.' || (*ptr)[1] == '#'))
			return (-1);
		(*ptr)++;
		*j = 0;
	}
	*i = 0;
	return (0);
}

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
		while (ptr[i] != '\n' && ptr[i] != '\0')
		{
			if (i >= 4)
				return (-1);
			i++;
		}
		if (i != 4 || ptr[i] == '\0')
			return (-1);
		ptr = ptr + i + 1;
		if (cut4x4(&i, &j, &ptr))
			return (-1);
	}
	return (0);
}

int		check_char_line(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (-1);
		i++;
	}
	j = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			j++;
		if (j >= 130)
			return (-1);
		i++;
	}
	return (0);
}

int		valid_file(char *str)
{
	if (check_char_line(str))
	{
		ft_putstr("Prob char ou trop de ligne\n");
		ft_strdel(&str);
		return (-1);
	}
	if (check4x4(str))
	{
		ft_putstr("C'est des carré de 4x4 avec des retour a la ligne\n");
		ft_strdel(&str);
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
