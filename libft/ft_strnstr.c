/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:28:06 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:47:06 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static	int	check(const char *haystack,
	const char *needle, size_t len, size_t i)
{
	size_t	x;

	x = 0;
	if (needle == 0)
		return (1);
	while (*(haystack + x) != '\0' && *(needle + x) != '\0' && i < len)
	{
		if (*(haystack + x) != *(needle + x))
			return (0);
		x++;
		i++;
	}
	if (*(needle + x) == '\0')
		return (1);
	else
		return (0);
}

char	*ft_strnstr(const char *haystack,
const char *needle, size_t len)
{
	size_t	x;

	x = 0;
	if (*(needle) == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (*(haystack + x) != '\0' && x < len)
	{
		if (*(haystack + x) == *(needle + 0))
		{
			if (check((haystack + x), (needle), len, x) == 1)
				return ((char *)(haystack + x));
		}
		x++;
	}
	return (NULL);
}
