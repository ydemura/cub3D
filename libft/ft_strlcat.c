/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:27:37 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:49:17 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	if (dstsize == 0)
		return (len_src);
	if (dstsize < len_dst)
		return (len_src + dstsize);
	if (dstsize > len_dst)
	{
		while (*(src + i) != '\0' && (len_dst + i) < (dstsize - 1))
		{
			*(dst + len_dst + i) = *(src + i);
			i++;
		}
		*(dst + len_dst + i) = '\0';
	}
	return (len_dst + len_src);
}
