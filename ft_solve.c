/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:51:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/02 11:49:56 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	move_first_piece(t_tetri **pieces, t_solution *solution, int inc, int i)
{
	ft_reset_grid(solution, inc);
	ft_translate_pieces(pieces, solution);
	ft_move_horizontal(solution, pieces[0], i);
}

int	ft_move_until_fit(t_tetri *piece, t_solution *solution, int inc)
{
	int	hor_count;
	int	vert_count;

	hor_count = 0;
	vert_count = 0;
	while (ft_check_if_fit(piece, solution, inc) == 0)
	{
		ft_move_horizontal(solution, piece, 1);
		hor_count++;
		if (hor_count == solution->min_size + inc)
		{
			ft_move_horizontal(solution, piece, - (solution->min_size + inc));
			ft_move_vertical(solution, piece, 1);
			vert_count++;
			hor_count = 0;
			if (vert_count == solution->min_size + inc)
			{
				ft_move_vertical(solution, piece, - (solution->min_size + inc));
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_if_solved(t_tetri **pieces, t_solution *solution, int inc)
{
	int	p;
	int	first_piece;

	first_piece = 0;
	p = 0;
	while (p < solution->nbr_pieces)
	{
		if (ft_check_if_fit(pieces[p], solution, inc) == 1)
		{
			ft_place_piece(solution, pieces[p], pieces[p]->ch);
			p++;
		}
		else
		{
			if (ft_move_until_fit(pieces[p], solution, inc) == 1)
				continue ;
			else
			{
				p = 0;
				first_piece++;
				move_first_piece(pieces, solution, inc, first_piece);
				if (first_piece == solution->min_size + inc)
					return (0);
			}
		}
	}
	return (1);
}

void ft_solve(t_tetri **pieces, t_solution *solution)
{
	int	inc;

	inc = 0;
	ft_create_grid(solution, inc);
	while (ft_check_if_solved(pieces, solution, inc) == 0)
	{
		inc += 1;
		ft_translate_pieces(pieces, solution);
		ft_create_grid(solution, inc);
	}
	printf("smallest square = %d\n", solution->min_size + inc);
	ft_print_array(solution->grid, solution->min_size + inc);
	ft_free_grid(solution, inc);
}
