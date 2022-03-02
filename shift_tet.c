/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_tet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:20:12 by trnguyen          #+#    #+#             */
/*   Updated: 2022/03/02 12:41:04 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_shift_tetri(t_tetri *piece, int y, int x)
{
	int i;

	i = 0;
	while (i < 4)
	{
		piece->y_coord[i] += y;
		piece->x_coord[i] += x;
		i++;
	}
}

// static int	min(int *array)
// {
// 	int min;
// 	int i;

// 	i = 0;
// 	min = array[0];
// 	while (array[i])
// 	{
// 		if (min > array[i])
// 			min = array[i];
// 		i++;
// 	}
// 	return (min);
// }

// void	ft_translate_pieces(t_tetri **pieces, t_solution *solution)
// {
// 	int	i;
// 	int min_x, min_y;

// 	i = 0;
// 	while (i < solution->nbr_pieces)
// 	{
// 		min_x = min(pieces[i]->x_coord);
// 		min_y = min(pieces[i]->y_coord);
// 		ft_shift_tetri(pieces[i], -min_y, -min_x);
// 		i++;
// 	}
// }
