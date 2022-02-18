/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:36:09 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/18 15:11:03 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_get_grid_size(t_grid grid)
{
	int cells;

	cells = grid.nbr_pieces * 4;
	if (ft_sqrt(cells) > 0)
		grid.min_size = ft_sqrt(cells);
	else
		grid.min_size = ft_find_next_sqrt(cells);
	printf("min grid size = %d\n", grid.min_size);
}