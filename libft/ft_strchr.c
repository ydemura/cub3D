/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/16 11:27:08 by adoner        #+#    #+#                 */
/*   Updated: 2022/11/20 15:51:08 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	s_len;

	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len + 1)
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
