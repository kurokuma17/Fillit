/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_check_fit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:06:24 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/16 17:11:33 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* check whether the piece will overflow the right-most line */
int	ft_check_right(int min_size, t_tetri *piece)
{
	int	i;

	i = 0;
	while (i < 4 && piece->y_coord[i] < min_size)
		i++;
	return (i == 4);
}

/* check whether the piece will overflow the bottom-most line */
int	ft_check_bottom(int min_size, t_tetri *piece)
{
	int	i;

	i = 0;
	while (i < 4 && piece->x_coord[i] < min_size)
		i++;
	return (i == 4);
}

/* check whether the grid has place for the piece */
int	ft_check_next_spot(t_solution *solution, t_tetri *piece)
{
	int	i;

	i = 0;
	while (i < 4 && solution->grid[piece->x_coord[i]][piece->y_coord[i]] == '.')
		i++;
	return (i == 4);
}
