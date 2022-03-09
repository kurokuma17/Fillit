/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:42:50 by deelliot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/09 14:49:38 by deelliot         ###   ########.fr       */
=======
/*   Updated: 2022/03/09 12:25:22 by trnguyen         ###   ########.fr       */
>>>>>>> c84de85f02093c4a36fcb092a0ec0ef6f37865ed
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
		free (pieces[i]);
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
