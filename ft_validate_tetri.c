/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:56:10 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/15 12:14:52 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_check_errors(char *tetri_str)
{
	int	block_count;
	int	empty_count;
	int	newline_count;

	block_count = 0;
	empty_count = 0;
	newline_count = 0;
	while (*tetri_str)
	{
		if (*tetri_str == '#')
			block_count++;
		if (*tetri_str == '.')
			empty_count++;
		if (*tetri_str == '\n')
			newline_count++;
		tetri_str++;
	}
	return (newline_count == 5 && block_count == 4 && empty_count == 12);
}

t_tetri	*ft_create_tetri(char *tetri_str)
{
	t_tetri	*new_piece;
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	new_piece = (t_tetri *)malloc(sizeof(t_tetri));
	if (!new_piece)
		return (NULL);
	while (*tetri_str != '\0')
	{
		c = *tetri_str;
		if (c != '\n')
			new_piece->cells[row][col] = c;
		col++;
		if (c == '\n')
		{
			row++;
			col = 0;
		}
		tetri_str++;
	}
	return (new_piece);
}

void	ft_store_tetri(t_tetri *new_piece, int piece_nbr)
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
				new_piece->c = 'A' + (piece_nbr - 1);
				i++;
			}
			//printf("piece[%d][%d] = %d\n", x, y, piece[x][y]);
			y++;
		}
		x++;
	}
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
	return (count);
}

int	ft_validate_tetri(char *buf, t_tetri pieces)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(buf) + 1;
	while (i < len)
	{
		temp = ft_strndup(&buf[i], 21);
		if (ft_check_errors(temp) != 1)
			return (-1);
		pieces[i / 21] = ft_create_tetri(temp);
		if (pieces[i / 21] == NULL)
			return (-1);
		ft_store_tetri(pieces[i / 21], i / 21);
		if (ft_check_alignment(pieces[i / 21] < 3))
			return (-1);
	}
	i = i + 21;
	return (1);
}
