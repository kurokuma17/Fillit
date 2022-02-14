/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:56:10 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/14 16:56:23 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_check_errors(char *piece)
{
	int	block_count;
	int	empty_count;
	int	newline_count;

	block_count = 0;
	empty_count = 0;
	newline_count = 0;
	while (*piece)
	{
		if (*piece == '#')
			block_count++;
		if (*piece == '.')
			empty_count++;
		if (*piece == '\n')
			newline_count++;
		piece++;
	}
	return (newline_count == 5 && block_count == 4 && empty_count == 12);
}

t_tetri	*ft_store_tetri(char **piece, t_tetri *new_piece, int nbr)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (piece[x][y] == '#')
			{
				new_piece->x_coord[i] = x;
				new_piece->y_coord[i] = y;
				new_piece->c = 'A' + (nbr - 1);
				new_piece->next = NULL;
				i++;
			}
			y++;
		}
		x++;
	}
	return (new_piece);
}

int	ft_check_alignment(t_tetri *new_piece)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = i + 1;
	count = 0;
	while (i < 4)
	{
		count += ft_abs((new_piece->x_coord[i] - new_piece->x_coord[j]) + \
			(new_piece->y_coord[i] - new_piece->y_coord[j]));
		i++;
	}
	printf("count = %d\n", count);
	return (count);
}

int	ft_validate_tetri(char *piece, int nbr)
{
	t_tetri	*new_piece;

	new_piece = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new_piece)
	{
		printf("unable to assign new_piece\n"); // error handling here
		return (-1);
	}
	if (ft_check_errors(piece) == 1)
	{
		new_piece = ft_store_tetri(&piece, new_piece, nbr);
		if (ft_check_alignment(new_piece) > 2)
			return (1);
		else
			printf("pieces not aligned\n");
			return (-1);
	}
	printf("unable to validate piece\n"); // error handling here
	return (-1);
}
