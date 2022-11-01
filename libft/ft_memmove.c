/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:26:35 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:47:37 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst1;
	const char	*src1;

	dst1 = (char *)dst;
	i = 0;
	src1 = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (len > i)
	{
		if (src > dst)
			*(dst1 + i) = *(src1 + i);
		else
			*(dst1 + len - i - 1) = *(src1 + len - i - 1);
		i++;
	}
	return (dst);
}
