/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:54:18 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/18 16:36:18 by deelliot         ###   ########.fr       */
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

typedef struct s_solution
{
	int			nbr_pieces;
	int			min_size;
	char		**grid;
}				t_solution;

int		ft_error(char *str, t_tetri **pieces, t_solution *solution);
void	ft_open_file(int fd, t_tetri **pieces, t_solution *solution);
void	ft_validate_tetri(char *buf, t_tetri **pieces, t_solution *solution);
void	ft_solve(t_solution *solution, t_tetri **pieces);
void	ft_print_array(char **array);

#endif
