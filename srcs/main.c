/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:40:05 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/18 15:50:40 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

char	*read_file(char *arg)
{
	char	*str;
	int		fd;

	if (!(str = (char *)malloc(sizeof(char) * BUFF + 1)))
		return (NULL);
	ft_bzero(str, BUFF + 1);
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_putstr("open fail\n");
		return (NULL);
	}
	if (read(fd, str, BUFF) < 0)
	{
		printf("Erreur de lecture\n");
		return (NULL);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Close Fail.\n");
		return (NULL);
	}
	return (str);
}

int		check_params(char argc)
{
	if (argc == 1 || argc > 2)
		return (-1);
	return (0);
}

int		all_error(int argc, char **argv, char **str, t_tetri **block)
{
	if (check_params(argc))
		return (usage());
	if (!(*str = read_file(argv[1])))
		return (error());
	if (valid_file(*str))
		return (error());
	ft_putstr("LE FICHIER EST VALIDE \nBIEN JOUE \n");
	if ((*block = parsing(read_file(argv[1]))) == NULL)
		return (error());
	return (0);
}

int		main(int argc, char **argv)
{
	char *str;
	char **map;
	t_tetri *block;
	int size;

	size = 2;
	str = NULL;
	if (all_error(argc, argv, &str, &block))
		return (-1);
	map = ini_map(size, 90);
	display_map(map);
	map = placeone(block->tetrimino, map, size);
	display_map(map);
	return (0);
}
