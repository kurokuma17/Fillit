/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:42:50 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/15 12:04:37 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_pieces(t_tetri **pieces)
{
	int	i;

	i = 0;
	while (pieces[i])
	{
		free (pieces);
		i++;
	}
}

int	ft_error(char *str, t_tetri **pieces)
{
	ft_free_pieces(pieces);
	ft_putendl(str);
	return (1);
}
