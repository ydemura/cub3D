/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 09:04:16 by ydemura       #+#    #+#                 */
/*   Updated: 2021/10/01 01:48:52 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_substr_number(char const *s, char c)
{
	int	n_substr;
	int	i;

	if (!s)
		return (0);
	n_substr = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			n_substr++;
		}
		i++;
	}
	return (n_substr);
}

static void	free_all(int i, char **array)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

static char	*m_s(const char *s, const char *end, int i, char **array)
{
	char	*substring;
	size_t	len_substr;

	len_substr = end - s;
	substring = (char *)malloc((len_substr + 1) * sizeof(char));
	if (substring == NULL)
	{
		free_all(i, array);
		return (NULL);
	}
	return (substring);
}

static void	*my_cp(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned int	i;
	unsigned char	*destination;
	unsigned char	*sorce;

	destination = (unsigned char *)dst;
	sorce = (unsigned char *)src;
	i = 0;
	while (i < n && (dst != (void *)0 || src != (void *)0))
	{
		destination[i] = sorce[i];
		i++;
	}
	destination[i] = '\0';
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	int			n_substr;
	char		**array;
	int			i;
	const char	*end;

	n_substr = ft_substr_number(s, c);
	array = (char **)malloc((n_substr + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < n_substr)
	{
		while (*s == c && *s != '\0')
			s++;
		end = s;
		while (*end != c && *end != '\0')
			end++;
		array[i] = m_s(s, end, i, array);
		my_cp(array[i], s, end - s);
		s = end + 1;
		i++;
	}
	array[i] = NULL;
	return (array);
}
