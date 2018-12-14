/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:40:05 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/14 16:55:51 by lubenard         ###   ########.fr       */
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
		return (NULL);
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
		return (usage());
	return (1);
}

int		main(int argc, char **argv)
{
	char *str;
	if (check_params(argc) == -1)
		return (-1);
	if (!(str = read_file(argv[1])))
		return (error());
	if (valid_file(str) == -1)
		return (error());
	else
		ft_putstr("LE FICHIER EST VALIDE \nBIEN JOUE \n");
	if (parsing(read_file(argv[1])) == NULL)
		return (error());
	return (0);
}
