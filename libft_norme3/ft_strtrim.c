/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 09:04:16 by ydemura       #+#    #+#                 */
/*   Updated: 2021/10/01 01:56:23 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_start_search(char const *s1, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s1[i] != '\0')
	{
		if (ft_memchr(set, s1[i], ft_strlen(set)) == NULL)
		{
			start = i;
			return (start);
		}
		i++;
	}
	return (0);
}

static int	ft_end_search(char const *s1, char const *set)
{
	int	i;
	int	end;
	int	len_s1;

	i = 0;
	end = 0;
	len_s1 = ft_strlen(s1);
	while (i < len_s1)
	{
		if (ft_memchr(set, s1[len_s1 - 1], ft_strlen(set)) == NULL)
		{
			end = len_s1;
			return (end);
		}
		len_s1--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len_s2;
	char	*s2;
	int		start;
	int		end;

	if (!s1 || !set)
		return (0);
	start = ft_start_search(s1, set);
	end = ft_end_search(s1, set);
	len_s2 = end - start;
	s2 = (char *)malloc((len_s2 + 1) * sizeof(char));
	if (s2 == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (start < end)
	{
		s2[i] = s1[start];
		start++;
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
