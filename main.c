/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:53:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/18 15:11:48 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>

void	ft_open_file(int fd, t_tetri **pieces)
{
	char	buf[547];
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, buf, 546);
	if (ret <= 0 || (ret + 1) % 21 != 0)
		ft_error("error in opening file", pieces);
	buf[ret] = '\n';
	buf[ret + 1] = '\0';
	printf("\033[1;33mSTART\n\033[0m");
	ft_validate_tetri(buf, pieces);
}

int	main(int argc, char **argv)
{
	t_tetri	*pieces[27];
	int		fd;

	if (argc != 2)
		ft_error("usage: ./fillit input_file", pieces);
	ft_bzero(pieces, sizeof(t_tetri *) * 27);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("unable to open file", pieces);
	ft_open_file(fd, pieces);
	close(fd);
	return (0);
}
