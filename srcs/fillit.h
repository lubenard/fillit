/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:22:26 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/18 16:51:23 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# include <stdio.h>

# define BUFF 1024

// t_teti t;

// t->c1[0];
// t->c1.x;

typedef struct s_coord
{
	int x;
	int y;
}			t_coord;

typedef struct	s_tetrimino
{
	char				**tetrimino;
	/*
	** crée fonction pour rempir c1 c2 ....
	*/
	t_coord 			c1;
	t_coord 			c2;
	t_coord 			c3;
	t_coord 			c4;
	t_coord 			pos;
	
	struct s_tetrimino	*prev;
	struct s_tetrimino	*next;
}				t_tetri;

char			**placeone(char **block, char **map, int size);
int				usage(void);
int				error(void);
t_tetri			*parsing(char *str);
int				valid_file(char *str);
char			**ini_map(int size, int max);
void			display_map(char **map);
int				verif_tetrimino(char **str);
int				optimize_tetri(char **str);

#endif
