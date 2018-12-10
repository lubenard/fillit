/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:40:05 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/10 13:39:08 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

char	*read_file(char *arg)
{
	char	*str;
	int		fd;

	if (!(fd = open(arg, O_RDONLY)))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * BUFF + 1)))
		return (NULL);
	read(fd, str, BUFF);
	str[BUFF + 1] = '\0';
	return (str);
}

int		check_params(char argc, char **argv)
{
	if (argc == 1 || argc > 2)
		return (usage());
	if (!(read_file(argv[1])))
		return (error());
	return (1);
}

int		main(int argc, char **argv)
{
	if (check_params(argc, argv) == 0)
		return (0);
	parsing(read_file(argv[1]));
	return (0);
}
