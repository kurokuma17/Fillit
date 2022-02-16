/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:14:09 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/16 15:35:05 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	ft_array_size(void **array)
{
	int	size;

	size = sizeof(array)/sizeof(array[0]);
	return (size);
}

void	**ft_memallocarray(size_t x, size_t y)
{
	void	**temp;
	size_t	i;

	i = 0;
	if (x == 0 || y == 0)
		return (NULL);
	temp = (void **)malloc(sizeof(*temp) * x);
	if (temp == NULL)
		return (NULL);
	while (i < x)
	{
		temp[i] = (void *)malloc(sizeof(*temp) * y);
		if (temp[i] == NULL)
			return (NULL);
		ft_memset(temp[i], '\0', y);
		i++;
	}
	return (temp);
}

int	main(void)
{
	int **array;
	size_t x = 4;
	size_t y = 5;
	int	array_size;

	array = (int **)ft_memallocarray(x, y);
	array_size = ft_array_size((void **)array);
	printf("no of elements = %d\n", array_size);
	return (0);
}