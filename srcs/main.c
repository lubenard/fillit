/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:40:05 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/02 12:58:11 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *arg)
{
	char	*str;
	int		fd;

	if (!(str = (char *)malloc(sizeof(char) * BUFF)))
		return (NULL);
	ft_bzero(str, BUFF);
	if ((fd = open(arg, O_RDONLY)) == -1)
	{
		ft_strdel(&str);
		return (NULL);
	}
	if (read(fd, str, BUFF) < 0)
	{
		ft_strdel(&str);
		return (NULL);
	}
	if (close(fd) == -1)
	{
		ft_strdel(&str);
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

int		all_error(int argc, char **argv, char *str, t_tetri **t)
{
	if (check_params(argc) == -1)
		return (usage());
	if (!(str = read_file(argv[1])))
	{
		printf("Return error read_file\n");
		return (error());
	}
	if (valid_file(str) == -1)
	{
		printf("return error valid file\n");
	}
	ft_putstr("LE FICHIER EST VALIDE \nBIEN JOUE \n");
	if ((*t = parsing(str)) == NULL)
	{
		printf("Parsing ????\n");
		ft_strdel(&str);
		return (error());
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*str;
	char	**map;
	t_tetri	*t;
	// int		size;
	// t_coord	pmap;
	// int retplace;
	// int retremove;

	// pmap.x = 1;
	// pmap.y = 1;
	// size = 4;
	str = NULL;
	if (all_error(argc, argv, str, &t))
		return (-1);
	map = solve(t);
	// map = ini_map(size, 90);
	// ft_putstr("La map au départ\n");
	// display_map(map);
	// retplace = place(t, map, pmap);
	// ft_putstr("Retplace = ");
	// ft_putnbr(retplace);
	// ft_putchar('\n');
	// ft_putstr("La map après\n");
	// display_map(map);
	// retremove = remove_p(t, map);
	// ft_putstr("Retremove = ");
	// ft_putnbr(retremove);
	// ft_putchar('\n');
	// ft_putstr("La map après\n");
	display_map(map);
	//print_all_list(t);
	return (0);
}
