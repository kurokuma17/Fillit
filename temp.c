/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:27:06 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/01 16:40:36 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_move_until_fit(t_tetri *piece, t_solution *solution, int inc)
{
	int	hor_count;
	int	vert_count;

	hor_count = 0;
	vert_count = 0;
	if (ft_check_if_fit(piece, solution, inc) == 0)
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