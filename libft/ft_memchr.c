/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:26:02 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/16 11:26:04 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*txt1;
	size_t				i;

	txt1 = s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == *(txt1 + i))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
