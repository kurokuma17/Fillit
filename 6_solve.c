/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:51:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/16 16:49:07 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_reset_and_move(t_tetri **pieces, int p, int x, int y)
{
	ft_reset_pieces(pieces, p);
	ft_translate_array(pieces[p]->x_coord, x);
	ft_translate_array(pieces[p]->y_coord, y);
}

static int	ft_check_if_solved(t_tetri **pieces, t_solution *solution, int p)
{
	int	hor_count;
	int	vert_count;

	vert_count = 0;
	if (!pieces[p])
		return (1);
	while (ft_check_bottom(solution->min_size, pieces[p]) == 1)
	{
		hor_count = 0;
		while (ft_check_right(solution->min_size, pieces[p]) == 1)
		{
			if (ft_check_next_spot(solution, pieces[p]) == 1)
			{
				ft_place_piece(solution, pieces[p], pieces[p]->ch);
				if (ft_check_if_solved(&pieces[p + 1], solution, p) == 1)
					return (1);
				else
					ft_place_piece(solution, pieces[p], '.');
			}
			ft_reset_and_move(pieces, p, vert_count, ++hor_count);
		}
		ft_reset_and_move(pieces, p, ++vert_count, 0);
	}
	return (0);
}

void	ft_solve(t_tetri **pieces, t_solution *solution)
{
	int	p;

	p = 0;
	ft_create_grid(solution);
	while (ft_check_if_solved(pieces, solution, p) == 0)
	{
		if (solution->grid)
			ft_free_grid(solution);
		solution->min_size += 1;
		ft_translate_pieces(pieces, solution);
		ft_create_grid(solution);
	}
	ft_print_array(solution->grid, solution->min_size);
	ft_free_grid(solution);
	ft_free_pieces(pieces);
	free(solution);
}
