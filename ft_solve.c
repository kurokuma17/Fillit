/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:51:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/02 14:42:39 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	move_first_piece(t_tetri **pieces, t_solution *solution, int count, int x)
{
	ft_reset_grid(solution);
	ft_translate_pieces(pieces, solution);
	ft_move_horizontal(solution, pieces[x], count);
}

void	move_piece_vert(t_tetri **pieces, t_solution *solution, int count, int x)
{
	ft_reset_grid(solution);
	ft_translate_pieces(pieces, solution);
	ft_move_vertical(solution, pieces[x], count);
}

int	ft_move_until_fit(t_tetri *piece, t_solution *solution)
{
	int	hor_count;
	int	vert_count;

	hor_count = 0;
	vert_count = 0;
	while (ft_check_if_fit(piece, solution) == 0)
	{
		ft_move_horizontal(solution, piece, 1);
		hor_count++;
		if (hor_count == solution->min_size)
		{
			ft_move_horizontal(solution, piece, - (solution->min_size));
			ft_move_vertical(solution, piece, 1);
			vert_count++;
			hor_count = 0;
			if (vert_count == solution->min_size)
			{
				ft_move_vertical(solution, piece, - solution->min_size);
				return (0);
			}
		}
	}
	return (1);
}

int	ft_check_if_solved(t_tetri **pieces, t_solution *solution)
{
	int	p;
	int i;
	int	count;
	int	vert_count;

	p = 0;
	i = 0;
	count = 0;
	vert_count = 0;
	while (p < solution->nbr_pieces)
	{
		if (ft_check_if_fit(pieces[p], solution) == 1)
		{
			ft_place_piece(solution, pieces[p], pieces[p]->ch);
			ft_print_array(solution->grid, solution->min_size);
			printf("\n\n");
			p++;
		}
		else
		{
			if (ft_move_until_fit(pieces[p], solution) == 1)
				continue ;
			else
			{
				p = 0;
				count++;
				move_first_piece(pieces, solution, count, p + i);
				if (count == solution->min_size)
				{
					count = 0;
					vert_count++;
					move_piece_vert(pieces, solution, vert_count, p + i);
					if (vert_count == solution->min_size)
					{
						count = 0;
						vert_count = 0;
						i++;
						if (i == solution->nbr_pieces)
							return (0);
					}
				}
			}
		}
	}
	return (1);
}

void ft_solve(t_tetri **pieces, t_solution *solution)
{
	ft_create_grid(solution);
	while (ft_check_if_solved(pieces, solution) == 0)
	{
		solution->min_size += 1;
		printf("solution size increased to: %d\n", solution->min_size);
		ft_translate_pieces(pieces, solution);
		ft_create_grid(solution);
	}
	printf("smallest square = %d\n", solution->min_size);
	ft_print_array(solution->grid, solution->min_size);
	ft_free_grid(solution);
}
