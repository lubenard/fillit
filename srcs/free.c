/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:19:38 by lubenard          #+#    #+#             */
/*   Updated: 2019/01/10 09:26:39 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetri(t_tetri *t)
{
	free(t->tetrimino[0]);
	free(t->tetrimino[1]);
	free(t->tetrimino[2]);
	free(t->tetrimino[3]);
	free(t->tetrimino);
	free(t);
}
