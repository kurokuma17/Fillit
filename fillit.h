/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 10:54:18 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/07 10:03:37 by trnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_tetri
{
	int			x_coord[4];
	int			y_coord[4];
	char		c;
	struct		s_tetri	*next;
}				t_tetri;

#endif
