/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoner <adoner@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 21:48:50 by adoner            #+#    #+#             */
/*   Updated: 2022/12/08 21:49:17 by adoner           ###   ########.fr       */
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
			return ((void *)(dst1 + i + 1));
		i++;
	}
	return (NULL);
}
