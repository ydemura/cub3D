/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:28:12 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:47:08 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (c == *(s + i))
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
