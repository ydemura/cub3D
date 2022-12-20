/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 12:25:09 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/16 13:43:29 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*a;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	a = (char *)malloc(ft_strlen(s) + 1);
	if (!a)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(a + i) = *(s + i);
		i++;
	}
	*(a + i) = '\0';
	i = 0;
	while (*(s + i) != '\0')
	{
		*(a + i) = (*f)(i, *(a + i));
		i++;
	}
	return (a);
}
