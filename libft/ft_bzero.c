/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 14:32:44 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:43:39 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = s;
	i = 0;
	while (i < n)
	{
		*(s1 + i) = 0;
		i++;
	}
}
