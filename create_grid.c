/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:13:47 by trnguyen          #+#    #+#             */
/*   Updated: 2022/03/02 16:11:42 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// malloc char array for grid and fill it with '.'

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

void	ft_reset_grid(t_solution *solution)
{
	int	i;

	i = 0;
	while (i < solution->min_size)
	{
		ft_memset(solution->grid[i], '.', solution->min_size);
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

// place the piece in the solution grid with the designated character
void	ft_place_piece(t_solution *solution, t_tetri *piece, char ch)
{
	int i;

	i = 0;
	while (i < 4)
	{
		solution->grid[piece->x_coord[i]][piece->y_coord[i]] = ch;
		i++;
	}
}

void ft_remove_pieces(t_solution *solution, t_tetri **pieces, int i, int p)
{
	int	j;
	int x;
	int y;
	t_tetri *piece;
	while (i > 0)
	{
		j = 0;
		p -= i;
		piece = pieces[p];
		printf("P: %c\n", piece->ch);
		while (j < 4)
		{
			x = piece->x_coord[j];
			y = piece->y_coord[j];
			printf("%c\n", solution->grid[x][y]);
			j++;
		}
		i--;
	}
}
// move the tetri horizontally
// y < 0: move left, y > 0: move right
void	ft_move_horizontal(t_solution *solution, t_tetri *piece, int y)
{
	int i;

	i = 0;
	while (solution && piece && i < 4)
	{
		piece->y_coord[i] += y;
		i++;
	}
}

// move the tetri vertically
// x < 0: move up, x > 0: move down
void	ft_move_vertical(t_solution *solution, t_tetri *piece, int x)
{
	int i;

	i = 0;
	while (solution && piece && i < 4)
	{
		piece->x_coord[i] += x;
		i++;
	}
}

void	ft_shift_tetri(t_solution *solution, t_tetri *piece, int y, int x)
{
	int i;

	i = 0;
	while (solution && piece && i < 4)
	{
		piece->y_coord[i] += y;
		piece->x_coord[i] += x;
		i++;
	}
}
