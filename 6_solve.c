/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_solve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:51:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/11 12:38:04 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_move_until_fit(t_tetri *piece, t_solution *solution)
{
	int	hor_count;
	int	vert_count;

	hor_count = 0;
	vert_count = 0;
	while (ft_check_if_fit(piece, solution) == 0)
	{
		ft_translate_array(piece->y_coord, 1);
		hor_count++;
		if (hor_count == solution->min_size)
		{
			ft_translate_array(piece->y_coord, - (solution->min_size));
			ft_translate_array(piece->x_coord, 1);
			vert_count++;
			hor_count = 0;
			if (vert_count == solution->min_size)
			{
				ft_translate_array(piece->x_coord, - (solution->min_size));
				return (0);
			}
		}
	}
	return (1);
}

static void	ft_backtrack(t_tetri **pieces, t_solution *solution, int p, int i)
{
	ft_remove_pieces(solution, pieces, i, p);
	ft_reset_pieces(pieces, solution, p);
	ft_translate_array(pieces[p]->y_coord, 1);
	if (ft_check_if_fit(pieces[p], solution) == 0)
	{
		ft_move_top_left(pieces[p]->y_coord);
		ft_translate_array(pieces[p]->x_coord, 1);
	}
}

static int	ft_check_if_solved(t_tetri **pieces, t_solution *solution)
{
	int	p;
	int	i;

	p = 0;
	i = 1;
	while (p < solution->nbr_pieces)
	{
		if (ft_check_if_fit(pieces[p], solution) == 1)
		{
			ft_place_piece(solution, pieces[p], pieces[p]->ch);
			p++;
		}
		else
		{
			if (ft_move_until_fit(pieces[p], solution) == 0)
			{
				p = p - i;
				if (p < 0)
					return (0);
				ft_backtrack(pieces, solution, p, i);
			}
		}
	}
	return (1);
}

void	ft_solve(t_tetri **pieces, t_solution *solution)
{
	ft_create_grid(solution);
	while (ft_check_if_solved(pieces, solution) == 0)
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
