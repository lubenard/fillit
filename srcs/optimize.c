/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:23:35 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/22 08:46:00 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	opti_horizontale(char **str)
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
}

void	opti_verticale(char **str)
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
}

int		detect_empty_line_hor(char **str, int i, int e)
{
	int nbr_pts_hor;
	int empty_line_hor;

	empty_line_hor = 0;
	nbr_pts_hor = 0;
	while (e < 4)
	{
		while (i < 4)
		{
			if (str[i][e] == '.')
				nbr_pts_hor++;
			else
				return (empty_line_hor);
			if (nbr_pts_hor == 4)
			{
				empty_line_hor++;
				nbr_pts_hor = 0;
			}
			i++;
		}
		e++;
		i = 0;
	}
	return (0);
}

int		detect_empty_line_ver(char **str, int i, int e)
{
	int nbr_pts_ver;
	int empty_line_ver;

	nbr_pts_ver = 0;
	empty_line_ver = 0;
	while (i < 4)
	{
		while (e < 4)
		{
			if (str[i][e] == '.')
				nbr_pts_ver++;
			else
				return (empty_line_ver);
			if (nbr_pts_ver == 4)
			{
				empty_line_ver++;
				nbr_pts_ver = 0;
			}
			e++;
		}
		i++;
		e = 0;
	}
	return (0);
}

int		optimize_tetri(char **str)
{
	int i;
	int e;
	int empty_line_hor;
	int empty_line_ver;

	i = 0;
	e = 0;
	empty_line_hor = 0;
	empty_line_ver = 0;
	empty_line_hor = detect_empty_line_hor(str, i, e);
	empty_line_ver = detect_empty_line_ver(str, i, e);
	while (empty_line_ver != 0)
	{
		opti_horizontale(str);
		empty_line_ver--;
	}
	while (empty_line_hor != 0)
	{
		opti_verticale(str);
		empty_line_hor--;
	}
	return (0);
}
