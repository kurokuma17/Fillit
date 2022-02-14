/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:53:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/14 16:56:25 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>

void	ft_open_file(int fd, char **pieces)
{
	char	buf[547];
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, buf, 546);
	if (ret <= 0 || (ret + 1) % 21 != 0)
	{
		printf("error in reading file\n"); // error handling to go here
		exit(1);
	}
	buf[ret] = '\n';
	buf[ret + 1] = '\0';
	while (i < ret)
	{
		pieces[i / 21] = strndup(&buf[i], 21);
		if (ft_validate_tetri(pieces[i / 21], i / 21) == 1)
		{
			printf("tetri piece is valid\n");
		}
		else
			printf("invalid piece\n"); // error handling here
		i = i + 21;
	}
}

int	main(int argc, char **argv)
{
	char	*pieces[27];
	int		fd;

	if (argc != 2)
		return (ft_error("usage: ./fillit input_file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("unable to open file"));
	ft_open_file(fd, pieces);
	close(fd);
	return (0);
}
