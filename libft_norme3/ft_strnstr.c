/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/22 09:04:16 by ydemura       #+#    #+#                 */
/*   Updated: 2021/10/01 01:51:27 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr_haystack;

	i = 0;
	j = 0;
	ptr_haystack = (char *)haystack;
	if (needle[j] == 0)
		return (ptr_haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0' && i + j < len)
				return (&ptr_haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}
