/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 13:33:02 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:47:01 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	**delete_item(char **s1, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}

static	int	skip_delim(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static	int	how_many_word(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	int	find_word_size(char const *s, int i, char c)
{
	int	count_size;

	count_size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		count_size++;
		i++;
	}
	return (count_size);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	int		i;
	int		count_size;
	int		size_word_count;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = how_many_word(s, c);
	size_word_count = 0;
	s1 = (char **)malloc(sizeof(s) * (word_count + 1));
	if (!s1)
		return (NULL);
	while (word_count > size_word_count)
	{
		i = skip_delim(s, c);
		count_size = find_word_size(s, i, c);
		s1[size_word_count] = ft_substr(s + i, 0, count_size);
		if (!s1[size_word_count])
			return (delete_item(s1, size_word_count));
		size_word_count++;
		s = s + i + count_size;
	}
	s1[size_word_count] = NULL;
	return (s1);
}
