/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:22:26 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/14 22:13:48 by jmoussu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# define BUFF 1024

typedef struct	s_tetrimino
{
	char				**tetrimino;
	struct s_tetrimino	*previous;
	struct s_tetrimino	*next;
}				t_tetrimino;

int				usage(void);
int				error(void);
t_tetrimino		*parsing(char *str);
int				valid_file(char *str);
char			**ini_map(int size, int max);
void			display_map(char **map);

#endif
