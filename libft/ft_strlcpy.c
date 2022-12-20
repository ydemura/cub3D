/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:27:44 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/16 11:53:23 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (src == NULL)
		return (0);
	while (*(src + i) != '\0' && (dstsize - 1) > i)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}
