/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:22:26 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/14 16:26:29 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# define BUFF 1024

typedef struct			s_tetrimino
{
	char				**tetrimino;
	struct s_tetrimino	*previous;
	struct s_tetrimino	*next;
}						t_tetrimino;

int						usage(void);
int						error(void);
int						valid_file(char *str);
t_tetrimino				*parsing(char *str);

#endif
