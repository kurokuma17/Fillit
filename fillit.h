/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:54:18 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/02 12:00:53 by deelliot         ###   ########.fr       */
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
	int				height;
	int				width;
	char			ch;
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
void	ft_get_min_grid_size(t_solution *solution);
void 	ft_set_height_width(t_tetri **pieces, t_solution *solution);
void	ft_find_height_width(t_tetri *piece);
void	ft_translate_array (int *array, int nbr);
void	ft_translate_pieces(t_tetri **pieces, t_solution *solution);
void	ft_print_array(char **array, int size);
void	ft_print_int_array(int *array);
void	ft_create_grid(t_solution *solution, int inc);
int		ft_check_if_fit(t_tetri *piece, t_solution *solution, int inc);
void	ft_place_piece(t_solution *solution, t_tetri *piece, char ch);
void 	ft_remove_pieces(t_solution *solution, t_tetri **pieces, int i, int p);
void	ft_move_horizontal(t_solution *solution, t_tetri *piece, int y);
void	ft_move_vertical(t_solution *solution, t_tetri *piece, int x);
void	ft_free_grid(t_solution *solution, int inc);
void	ft_reset_grid(t_solution *solution, int inc);
void	move_first_piece(t_tetri **pieces, t_solution *solution, int inc, int count, int x);
void	ft_solve(t_tetri **pieces, t_solution *solution);

int	solver(t_solution *solution, t_tetri **pieces);

#endif
