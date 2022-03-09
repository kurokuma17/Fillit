/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:42:50 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/09 16:57:30 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_pieces(t_tetri **pieces)
{
	int	i;
	int	j;

	i = 0;
	while (pieces[i])
	{
		j = 0;
		while (j < 4)
			ft_strdel(&(pieces[i]->cells[j++]));
		free(pieces[i]->cells);
		free(pieces[i]);
		i++;
	}
}

int	ft_error(char *str, t_tetri **pieces, t_solution *solution)
{
	ft_free_pieces(pieces);
	free (solution);
	ft_putendl(str);
	exit(1);
}
