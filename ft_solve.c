/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:51:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/25 11:00:27 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_check_if_fit(t_tetri *piece, t_solution *solution, int inc)
{
	if (ft_check_next_spot(solution, piece) == 1 && \
		ft_check_bottom(solution->min_size + inc, piece) == 1 && \
		ft_check_right(solution->min_size + inc, piece) == 1)
		return (1);
	else
		return (0);
}

int	ft_check_if_solved(t_tetri **pieces, t_solution *solution, int inc)
{
	int	p;
	int hor_count;
	int vert_count;

	p = 0;
	hor_count = 0;
	vert_count = 0;
	while (p < solution->nbr_pieces)
	{
		if (ft_check_if_fit(pieces[p], solution, inc) == 1)
		{
			hor_count = 0;
			vert_count = 0;
			ft_place_piece(solution, pieces[p], pieces[p]->ch);
			ft_print_array(solution->grid, solution->min_size + inc);
			p++;
		}
		else
		{
			ft_print_int_array(pieces[p]->x_coord);
			ft_print_int_array(pieces[p]->y_coord);

			ft_move_horizontal(solution, pieces[p], 1);
			//printf("moved horizontal\n");
			hor_count++;
			if (hor_count == solution->min_size + inc)
			{
				ft_move_horizontal(solution, pieces[p], -(solution->min_size + inc));
				ft_move_vertical(solution, pieces[p], 1);
				//printf("moved vertically\n");
				vert_count++;
				hor_count = 0;
				if (vert_count == solution->min_size + inc)
				{
					printf("ver count = %d\n", vert_count);
					return (1);
				}

			}

			ft_print_int_array(pieces[p]->x_coord);
			ft_print_int_array(pieces[p]->y_coord);

			printf("\n\n");
		}
	}
	return (1);
}

void ft_solve(t_tetri **pieces, t_solution *solution)
{
	int	inc;

	inc = 0;
	ft_create_grid(solution, inc);
	if (ft_check_if_solved(pieces, solution, inc) == 1)
		ft_print_array(solution->grid, solution->min_size + inc);
	else
	{
		inc += 1;
		ft_create_grid(solution, inc);
		printf("grid size increased by 1\n");
		ft_check_if_solved(pieces, solution, inc);
	}
}