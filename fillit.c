/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:36:09 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/18 16:12:58 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_get_grid_size(t_solution *solution)
{
	int cells;

	cells = solution->nbr_pieces * 4;
	if (ft_sqrt(cells) > 0)
		solution->min_size = ft_sqrt(cells);
	else
		solution->min_size = ft_find_next_sqrt(cells);
	printf("min solution size = %d\n", solution->min_size);
}

void	ft_solve (t_solution *solution, t_tetri **pieces)
{
	ft_get_grid_size(solution);
	printf("%c\n", pieces[1]->c);
}