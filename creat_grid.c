/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 23:13:47 by trnguyen          #+#    #+#             */
/*   Updated: 2022/02/25 11:00:31 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

// malloc char array for grid and fill it with '.'

void	ft_free_grid(t_solution *solution, int inc)
{
	int	i;

	i = 0;
	while (i < (inc - 1))
	{
		free (solution->grid[i]);
		i++;
	}

}

void	ft_create_grid(t_solution *solution, int inc)
{
	int	i;

	i = 0;
	if (solution)
	{
		if (solution->grid)
			ft_free_grid(solution, inc);
		solution->grid = (char **)ft_memallocarray(solution->min_size + inc, \
		solution->min_size + inc);
		while (i < solution->min_size + inc)
		{
			ft_memset(solution->grid[i], '.', solution->min_size + inc);
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

// check whether the grid has place for the piece
int ft_check_next_spot(t_solution *solution, t_tetri *piece)
{
	int i;

	i = 0;
	while (i < 4 && solution->grid[piece->x_coord[i]][piece->y_coord[i]] == '.')
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
}

// check whether the piece will overflow the bottom-most line
int	ft_check_bottom(int size, t_tetri *piece)
{
	int i;

	i = 0;
	while (i < 4 && piece->x_coord[i] < size)
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
}

// check whether the piece will overflow the right-most line
int	ft_check_right(int size, t_tetri *piece)
{
	int i;

	i = 0;
	while (i < 4 && piece->y_coord[i] < size)
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
}

// move the tetri horizontally
// y < 0: move left, y > 0: move right
void	ft_move_horizontal(t_solution *solution, t_tetri *piece, int y)
{
	if (solution && piece)
	{
		for (int i = 0; i < 4; i++)
			piece->y_coord[i] += y;
	}
}

// move the tetri vertically
// x < 0: move up, x > 0: move down
void	ft_move_vertical(t_solution *solution, t_tetri *piece, int x)
{
	if (solution && piece)
	{
		for (int i = 0; i < 4; i++)
			piece->x_coord[i] += x;
	}
}