/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:26:26 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:47:27 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src1;
	size_t		i;
	char		*dst1;

	if (!src && !dst)
		return (0);
	src1 = src;
	dst1 = dst;
	i = 0;
	while (n > i)
	{
		*(dst1 + i) = *(src1 + i);
		i++;
	}
	return (dst);
}
