/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate_pieces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:52:54 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/21 12:49:58 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

//this function finds the lowest value in the array, and subtracts it from
//each element in the array.

void	ft_find_min(int *array)
{
	int	min;
	int	i;

	i = 0;
	min = array[i];
	while (i < 3)
	{
		if (min > array[i + 1])
			min = array[i + 1];
		i++;
	}
	i = 0;
	while (i < 4)
	{
		array[i] -= min;
		i++;
	}
}

// moves the pieces to the top most left area possible

void	ft_translate_pieces(t_tetri **pieces, t_solution *solution)
{
	int	i;

	i = 0;
	while (i < solution->nbr_pieces)
	{
		ft_find_height_width(pieces[i]);
		if(solution->min_size < ft_max(pieces[i]->height, pieces[i]->width))
		{
			solution->min_size = ft_max(pieces[i]->height, pieces[i]->width);
			printf("new min size = %d\n", solution->min_size);
		}
		ft_find_min(pieces[i]->x_coord);
		ft_find_min(pieces[i]->y_coord);
		i++;
	}
}
