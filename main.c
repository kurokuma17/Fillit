/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:53:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/07 12:03:58 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>

// t_tetri	**ft_create_tetri(char **pieces)
// {
	
// }

int	valid_tetri(char *piece)
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
// still need to check if 4 blocks align as a valid tetrimino

void	ft_open_file(int fd, char **pieces)
{
	char	buf[547];
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, buf, 546);
	if (ret <= 0 || ret == 546 || (ret + 1) % 21 != 0)
		printf("error\n"); // error handling to go here
	buf[ret + 1] = '\0';
	while (i < ret)
	{
		pieces[i/21] = strndup(&buf[i], 21);
		//check for errors
		i = i + 21;
	}
}

int main(int argc, char **argv)
{
	char	*pieces[27];
	int		fd;

	if (argc != 2)
	{
		printf("too many files\n"); //this is where we should print usage
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("unable to open file\n"); //error handing to go here
		return (1);
	}
	ft_open_file(fd, pieces);
	printf("%s", pieces[0]);
	printf("%d", valid_tetri(pieces[0]));
	//carry on with rest of functions
}

