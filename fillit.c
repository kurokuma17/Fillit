/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:36:09 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/21 13:12:52 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_get_min_grid_size(t_solution *solution)
{
	int	cells;

	cells = solution->nbr_pieces * 4;
	if (ft_sqrt(cells) > 0)
		solution->min_size = ft_sqrt(cells);
	else
		solution->min_size = ft_find_next_sqrt(cells);
}

void	ft_solve(t_tetri **pieces, t_solution *solution)
{
	int	i;
	int	j;
	int	k;
	int	p;
	char temp[solution->min_size][solution->min_size];

	ft_memset((void*)temp, '.', sizeof(char) * (solution->min_size * \
		solution->min_size));
	i = 0;
	k = 0;
	p = 0;
	while (i < solution->min_size)
	{
		j = 0;
		while(j < solution->min_size)
		{
			if (temp[i][j] == '.')
			{
				if (pieces[p]->x_coord[k] == i && pieces[p]->y_coord[k] == j)
				{
					temp[i][j] = pieces[p]->ch;
					k++;
				}
			}
			j++;
		}
		i++;
	}

	//just prints out current solution

	i = 0;
	while (i < solution->min_size)
	{
		j = 0;
		while (j < solution->min_size)
		{
			ft_putchar(temp[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
