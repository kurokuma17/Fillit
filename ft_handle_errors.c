/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:42:50 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/24 23:19:45 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// theorectically frees each piece of the struct, don't know how to test...

static void	ft_free_pieces(t_tetri **pieces)
{
	int	i;

	i = 0;
	while (pieces[i])
	{
		free (pieces[i]);
		i++;
	}
}

//once freed, writes the error message followed by a nl and exits

int	ft_error(char *str, t_tetri **pieces, t_solution *solution)
{
	ft_free_pieces(pieces);
	free (solution);
	ft_putendl(str);
	exit(1);
}
