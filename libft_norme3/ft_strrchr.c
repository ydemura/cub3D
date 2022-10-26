/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: julia <julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 14:37:36 by julia         #+#    #+#                 */
/*   Updated: 2021/10/01 01:51:40 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		len;

	str = (char *)s;
	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	if (s[len] == '\0' && c == '\0')
	{
		return (&str[len]);
	}
	while (len >= 0)
	{
		if (s[len] == (unsigned char)c)
		{
			return (&str[len]);
		}
		len--;
	}
	return (0);
}
