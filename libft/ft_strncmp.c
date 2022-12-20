/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:28:00 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:47:04 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*(st2 + i) != *(st1 + i))
			return (*(st1 + i) - *(st2 + i));
		if (*(st1 + i) == '\0' && *(st2 + i) == '\0')
			return (0);
		i++;
	}
	return (0);
}
