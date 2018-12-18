/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:23:35 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/18 18:31:14 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 		opti_horizontale(char **str)
{
	int e;
	int i;


	i = 0;
	e = 0;
	while (e < 4)
	{
		while (i + 1 < 4)
		{
			str[i][e] = str[i + 1][e];
			str[i + 1][e] = '.';
			i++;
		}
		i = 0;
		e++;
	}
	printf("File:\n%s\n%s\n%s\n%s\n", str[0], str[1], str[2], str[3]);
}

void		opti_verticale(char **str)
{
	int i;
	int e;

	e = 0;
	i = 0;
	while (i < 4)
	{
		while (e + 1 < 4)
		{
			str[i][e] = str[i][e + 1];
			str[i][e + 1] = '.';
			e++;
		}
		e = 0;
		i++;
	}
	printf("File :\n%s\n%s\n%s\n%s\n", str[0], str[1], str[2], str[3]);
}

int			optimize_tetri(char **str)
{
	int i;
	int e;
	int empty_line_hor;
	int empty_line_ver;
	int y;

	i = 0;
	e = 0;
	y = 0;
	empty_line_hor = 0;
	empty_line_ver = 0;

	while (y < 4)
	{
		while (i < 4)
		{
			if (str[i][e] != '.')
			{
				printf("str[%d][%d] non nul hori\n", i, e);
				printf("Ligne horizontale non vide\n");
				empty_line_hor++;
			}
			i++;
		}
		e++;
		i = 0;
		y++;
	}
	y = 0;
	i = 0;
	while (y < 4)
	{
		while (e < 4)
		{
			if (str[i][e] != '.')
			{
				printf("str[%d][%d] non nul vert\n", i, e);
				printf("Ligne verticale non vide\n");
				empty_line_ver++;
			}
			e++;
		}
		i++;
		e = 0;
		y++;
	}
	printf("empty_line_ver = %d\nempty_ligne_hor = %d\n", empty_line_ver, empty_line_hor);
	printf("%s\n%s\n%s\n%s\n", str[0], str[1], str[2], str[3]);
	return (0);
}
