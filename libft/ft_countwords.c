/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <lubenard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:29:37 by lubenard          #+#    #+#             */
/*   Updated: 2018/12/06 17:27:34 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_countwords(char const *s)
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if (s[i] <= 33 && s[i + 1] > 32)
			nbr++;
		i++;
	}
	if (nbr == 0)
		return (0);
	return (nbr + 1);
}
