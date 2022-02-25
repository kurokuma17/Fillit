/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:31:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/25 11:00:28 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_array(char **array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(array[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_print_int_array(int *array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_putnbr(array[i]);
		i++;
	}
	ft_putchar('\n');
}
