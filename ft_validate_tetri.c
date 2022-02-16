/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:56:10 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/16 14:18:41 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

//this function checks that there are the correct number of blocks
// empty spaces and newlines

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
	printf("nl: %d\nempty: %d\nblocks: %d\n", newline_count, empty_count, block_count);
	return (newline_count == 5 && block_count == 4 && empty_count == 12);
}

//this function assigns memory for each new tetrimoni struct, and converts the
// buf str into a 2d array, which is saved in the struct

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
	new_piece->cells = (char **)ft_memallocarray(4, 4);
	if (new_piece->cells == NULL)
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

	// this just prints the 2d array - just using for testing, we will remove
	//it after :)

	int i = 0;
	int j = 0;

	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%c", new_piece->cells[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (new_piece);
}

//this just fills in the remaining variables in the struct

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
			if (new_piece->cells[x][y] == '#')
			{
				new_piece->x_coord[i] = x;
				new_piece->y_coord[i] = y;
				new_piece->c = 'A' + piece_nbr;
				i++;
			}
			y++;
		}
		x++;
	}
	printf("new piece ch: %c\n", new_piece->c);
}

// this checks that the pieces are correctly aligned

int	ft_check_alignment(t_tetri *new_piece)
{
	int	i;
	int	j;
	int temp;
	int count;

	i = 0;
	count = 0;
	while(i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			temp = (ft_abs((new_piece->x_coord[i]- new_piece->x_coord[j]))) + \
			(ft_abs((new_piece->y_coord[i]- new_piece->y_coord[j])));
			if (temp == 1)
				count++;
			j++;
		}
		i++;
	}
	printf("count = %d\n", count);
	return (count);
}

//loops through each piece in the file, checks for errors,
// coverts str to 2d array, and then stores in it the struct

void	ft_validate_tetri(char *buf, t_tetri **pieces)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	len = ft_strlen(buf);
	while (i < len)
	{
		temp = ft_strndup(&buf[i], 21);
		if (ft_check_errors(temp) != 1)
			ft_error("error in tetri", pieces);
		pieces[i / 21] = ft_create_tetri(temp);
		if (pieces[i / 21] == NULL)
			ft_error("unable to malloc", pieces);
		ft_store_tetri(pieces[i / 21], i / 21);
		if ((ft_check_alignment(pieces[i / 21]) < 3))
			ft_error("piece not aligned", pieces);
		i += 21;
		printf("i = %d\n", i);
		printf("strlen = %d\n\n", len);

	}
}
