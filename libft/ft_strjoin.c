/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:27:29 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:47:03 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		totallen;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	totallen = ft_strlen(s1) + ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (totallen + 1));
	if (!c)
		return (NULL);
	while (*s1 != '\0')
	{
		*(c + i) = *s1;
		++s1;
		i++;
	}
	while (*s2 != '\0')
	{
		*(c + i) = *s2;
		++s2;
		i++;
	}
	*(c + i) = '\0';
	return (c);
}
