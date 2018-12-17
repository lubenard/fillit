/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 10:03:27 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/17 12:07:09 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		check_connections(char **str, int i, int e, int connections)
{
	if (i != 0 && str[i - 1][e] == '#')
		connections++;
	if (i != 3 && str[i + 1][e] == '#')
		connections++;
	if (e != 0 && str[i][e - 1] == '#')
		connections++;
	if (e != 3 && str[i][e + 1] == '#')
		connections++;
	return (connections);
}

int		verif_tetrimino(char **str)
{
	int i;
	int e;
	int compteur;
	int connections;

	i = 0;
	compteur = 0;
	connections = 0;
	while (i < 4)
	{
		e = 0;
		while (e < 4)
		{
			if (str[i][e] == '#')
			{
				connections = check_connections(str, i, e, connections);
				compteur++;
			}
			e++;
		}
		i++;
	}
	printf("connections = %d compteur = %d\n", connections, compteur);
	if (compteur != 4 || (connections != 6 && connections != 8))
		return (-1);
	return (0);
}
