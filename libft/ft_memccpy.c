/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:25:52 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:46:28 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	i = 0;
	while (i < n)
	{
		*(dst1 + i) = *(src1 + i);
		if (*(src1 + i) == (char)c)
			return ((void*)(dst1 + i + 1));
		i++;
	}
	return (NULL);
}
