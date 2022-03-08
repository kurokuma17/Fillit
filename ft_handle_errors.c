/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:42:50 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/08 09:55:21 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int	ft_error(char *str, t_tetri **pieces, t_solution *solution)
{
	ft_free_pieces(pieces);
	free (solution);
	ft_putendl(str);
	exit(1);
}
