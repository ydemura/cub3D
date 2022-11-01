/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 14:32:56 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/21 14:32:58 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*s1;
	size_t	i;

	i = 0;
	s1 = (void *)malloc(count * size);
	if (s1 == NULL)
		return (0);
	while ((count * size) > i)
	{
		((char *)s1)[i] = 0;
		i++;
	}
	return (s1);
}
