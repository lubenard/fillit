/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoussu <jmoussu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:22:26 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/12 16:04:15 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

# define BUFF 1024

int					usage(void);
int					error(void);
void				parsing(char *str);
int					valid_file(char *str);

typedef struct		s_triomino
{
	char				*firstline;
	char				*secondline;
	char				*thirdline;
	char				*lastline;
	struct s_triomino	*previous;
	struct s_triomino	*next;
}					t_triomino;

#endif
