/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_h_w.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:30:44 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/21 10:53:53 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

//find the max h and w of each tetrimoni and stores it in the struct

void	ft_find_height_width(t_tetri *piece)
{
	int	i;
	int	j;

	i = 0;
	piece->height = 0;
	piece->width = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (piece->height < ft_abs(piece->x_coord[i] - piece->x_coord[j]))
				piece->height = ft_abs(piece->x_coord[i] - piece->x_coord[j]);
			if (piece->width < ft_abs(piece->y_coord[i] - piece->y_coord[j]))
				piece->width = ft_abs(piece->y_coord[i] - piece->y_coord[j]);
			j++;
		}
		i++;
	}
	piece->height += 1;
	piece->width += 1;
}
