/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:53:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/15 12:02:05 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <string.h>

char	*ft_open_file(int fd, t_tetri *pieces)
{
	char	buf[547];
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, buf, 546);
	if (ret <= 0 || (ret + 1) % 21 != 0)
		return (NULL);
	buf[ret] = '\n';
	buf[ret + 1] = '\0';
	return (buf);
}

int	main(int argc, char **argv)
{
	t_tetri	pieces[27];
	int		fd;
	char	*buf;

	if (argc != 2)
		return (ft_error("usage: ./fillit input_file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error("unable to open file"));
	buf = ft_open_file(fd, pieces);
	if (buf == NULL)
		return (ft_error("error"));
	close(fd);
	if (ft_validate_tetri(buf, pieces) != 1)
		return (ft_error("error"));
	return (0);
}
