/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 08:59:43 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/01 08:59:59 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_reset_grid(t_solution *solution, int inc)
{
	int	i;

	i = 0;
	while (i < solution->min_size + inc)
	{
		ft_memset(solution->grid[i], '.', solution->min_size + inc);
		i++;
	}
}

void	move_first_piece(t_tetri **pieces, t_solution *solution, int inc, int i)
{
	ft_reset_grid(solution, inc);
	ft_translate_pieces(pieces, solution);
	ft_move_horizontal(solution, pieces[0], i);
}

void	remove_piece(t_tetri *piece, t_solution *solution)
{
	int i;

	i = 0;
	while (i < 4)
	{
		solution->grid[piece->x_coord[i]][piece->y_coord[i]] = '.';
		i++;
	}
}

void  move_prev_piece(t_tetri **pieces, t_solution *solution, int i)
{
	remove_piece(pieces[p - 1], solution);
	ft_move_horizontal(solution, pieces[p - 1], i);
}