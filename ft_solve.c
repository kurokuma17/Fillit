/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:51:59 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/07 16:42:08 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_move_until_fit(t_tetri *piece, t_solution *solution)
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

void	ft_remove_pieces(t_solution *solution, t_tetri **pieces, int i, int p)
{
	int	j;

	while (i > 0)
	{
		j = 0;
		while (j < 4)
		{
			solution->grid[pieces[p]->x_coord[j]][pieces[p]->y_coord[j]] = '.';
			j++;
		}
		p++;
		i--;
	}
}

void	ft_reset_pieces(t_tetri **pieces, t_solution *solution, int p)
{
	int	i;

	i = p + 1;
	while (i < solution->nbr_pieces)
	{
		ft_move_top_left(pieces[i]->x_coord);
		ft_move_top_left(pieces[i]->y_coord);
		i++;
	}
}

int	ft_check_if_solved(t_tetri **pieces, t_solution *solution)
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
			ft_print_array(solution->grid, solution->min_size);
			printf("\n\n");
			p++;
		}
		else
		{
			if (ft_move_until_fit(pieces[p], solution) == 1)
			{
				continue ;
			}
			else
			{
				printf("unable to place: %c\n", pieces[p]->ch);
				p = p - i;
				if (p < 0)
					return (0);
				ft_remove_pieces(solution, pieces, i, p);
				ft_reset_pieces(pieces, solution, p);
				ft_translate_array(pieces[p]->y_coord, 1);
				if (ft_check_right(solution->min_size, pieces[p]) == 0)
				{
					ft_move_top_left(pieces[p]->y_coord);
					ft_translate_array(pieces[p]->x_coord, 1);
					if (ft_check_bottom(solution->min_size, pieces[p]) == 0)
					{
						i++;
						if (p - i < 0)
						{
							ft_print_array(solution->grid, solution->min_size);
							return (0);
						}
				 	}
				}
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
		solution->min_size += 1;
		ft_translate_pieces(pieces, solution);
		ft_create_grid(solution);
	}
	printf("smallest square = %d\n", solution->min_size);
	ft_print_array(solution->grid, solution->min_size);
	ft_free_grid(solution);
}
