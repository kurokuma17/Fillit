/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:13:47 by trnguyen          #+#    #+#             */
/*   Updated: 2022/03/08 09:59:02 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* malloc char array for grid and fill it with '.'*/

void	ft_get_min_grid_size(t_solution *solution)
{
	int	cells;

	cells = solution->nbr_pieces * 4;
	if (ft_sqrt(cells) > 0)
		solution->min_size = ft_sqrt(cells);
	else
		solution->min_size = ft_find_next_sqrt(cells);
}

void	ft_free_grid(t_solution *solution)
{
	int	i;

	i = 0;
	while (i < (solution->min_size - 1))
	{
		free (solution->grid[i]);
		i++;
	}
}

void	ft_create_grid(t_solution *solution)
{
	int	i;

	i = 0;
	if (solution)
	{
		if (solution->grid)
			ft_free_grid(solution);
		solution->grid = (char **)ft_memallocarray(solution->min_size, \
		solution->min_size);
		while (i < solution->min_size)
		{
			ft_memset(solution->grid[i], '.', solution->min_size);
			i++;
		}
	}
}

/* place the piece in the solution grid with the designated character*/
void	ft_place_piece(t_solution *solution, t_tetri *piece, char ch)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		solution->grid[piece->x_coord[i]][piece->y_coord[i]] = ch;
		i++;
	}
}

void	ft_remove_pieces(t_solution *solution, t_tetri **pieces, int i, int p)
{
	int	j;

	while (i > 0)
	{
		j = 0;
		while (j < 4)
		{
			if (solution->grid[pieces[p]->x_coord[j]][pieces[p]->y_coord[j]] \
				== pieces[p]->ch)
				solution->grid[pieces[p]->x_coord[j]][pieces[p]->y_coord[j]] \
				= '.';
			j++;
		}
		p++;
		i--;
	}
}
