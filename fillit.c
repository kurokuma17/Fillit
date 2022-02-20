/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:36:09 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/20 18:38:28 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

//this function finds the lowest value in the array, and subtracts it from
//each element in the array.

void	ft_transform_array(int *array)
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

// moves the piece to the top most left area possible

void	ft_store_new_x_coords(t_tetri **pieces, t_solution *solution)
{
	int	i;

	i = 0;
	while (i < solution->nbr_pieces)
	{
		ft_transform_array(pieces[i]->x_coord);
		ft_transform_array(pieces[i]->y_coord);
		i++;
	}
}

void	ft_get_grid_size(t_solution *solution)
{
	int	cells;

	cells = solution->nbr_pieces * 4;
	if (ft_sqrt(cells) > 0)
		solution->min_size = ft_sqrt(cells);
	else
		solution->min_size = ft_find_next_sqrt(cells);
	printf("min solution size = %d\n", solution->min_size);
}

void	ft_solve(t_tetri **pieces, t_solution *solution)
{
	ft_get_grid_size(solution);
	ft_store_new_x_coords(pieces, solution);
}
