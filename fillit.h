/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:54:18 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/18 15:11:06 by deelliot         ###   ########.fr       */
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

typedef struct	s_grid
{
	int			nbr_pieces;
	int			min_size;
}				t_grid;

int		ft_error(char *str, t_tetri **pieces);
void	ft_open_file(int fd, t_tetri **pieces);
void	ft_validate_tetri(char *buf, t_tetri **pieces);
int		ft_get_min_grid_size(t_tetri **pieces);
void	ft_get_grid_size(t_grid grid);

#endif
