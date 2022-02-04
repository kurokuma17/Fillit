/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:53:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/04 11:36:57 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_piece	*pieces[27];
	int		fd;

	if (argc != 2)
	{
		printf("too many files\n"); //this is where we should print usage
		return (1);
	}
	fd = open(argv[1], O_RDONLY)
	if (fd < 0)
	{
		printf("unable to open file\n"); //error handing to go here
		return (1);
	}

}

void	ft_open_file(int fd, t_piece **pieces)
{
	char	buf[547];
	int		ret;
	int		i;

	i = 0;
	ret = read(fd, buf, 546)
	if (ret <= 0 || ret == 546 || (ret + 1) % 21 != 0)
		printf("error\n"); // error handling to go here
	buf[ret + 1] = '\0';
	while (i < ret)
	{
		pieces[i/21] = ft_cpy_to_structure(i, pieces)
	}
}