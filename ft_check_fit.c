/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:06:24 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/08 11:04:15 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* check whether the piece will overflow the right-most line */
static int	ft_check_right(int size, t_tetri *piece)
{
	int	i;

	i = 0;
	while (i < 4 && piece->y_coord[i] < size)
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
}

/* check whether the piece will overflow the bottom-most line */
static int	ft_check_bottom(int size, t_tetri *piece)
{
	int	i;

	i = 0;
	while (i < 4 && piece->x_coord[i] < size)
		i++;
	if (i == 4)
		return (1);
	else
	{
		return (0);
	}
}

/* check whether the grid has place for the piece */
static int	ft_check_next_spot(t_solution *solution, t_tetri *piece)
{
	int	i;

	i = 0;
	while (i < 4 && solution->grid[piece->x_coord[i]][piece->y_coord[i]] == '.')
		i++;
	if (i == 4)
		return (1);
	else
		return (0);
}

int	ft_check_if_fit(t_tetri *piece, t_solution *solution)
{
	if (ft_check_right(solution->min_size, piece) == 1 && \
		ft_check_bottom(solution->min_size, piece) == 1 && \
		ft_check_next_spot(solution, piece) == 1)
		return (1);
	else
		return (0);
}
