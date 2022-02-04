/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:00:05 by deelliot          #+#    #+#             */
/*   Updated: 2022/01/25 16:49:37 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strcat() and strncat() functions append a copy of the null-terminated
// string s2 to the end of the null-terminated string s1, then add a
// terminating `\0'.The string s1 must have sufficient space to hold the
// result.

// The strncat() function appends not more than n characters from s2, and then
// adds a terminating `\0'.

char	*ft_strcat(char *dest, const char *src)

{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
