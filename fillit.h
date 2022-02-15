/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:54:18 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/15 12:02:25 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct s_tetri
{
	char			**cells;
	int				x_coord[4];
	int				y_coord[4];
	char			c;
}				t_tetri;

int		ft_error(char *str);
void	ft_open_file(int fd, char **pieces);
int		ft_validate_tetri(char *piece, int nbr);

#endif
