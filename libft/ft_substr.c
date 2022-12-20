/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:28:23 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:46:34 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*biggerstart(void)
{
	char	*c;

	c = (char *)malloc(sizeof(char) * 1);
	if (!c)
		return (NULL);
	*c = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (len_s < start)
		return (biggerstart());
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	while (*(s + start) != '\0' && len != 0)
	{
		*(c + i) = *(s + start + i);
		i++;
		len--;
	}
	*(c + i) = '\0';
	return (c);
}
