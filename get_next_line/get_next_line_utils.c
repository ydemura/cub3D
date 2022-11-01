/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 11:34:41 by catalina      #+#    #+#                 */
/*   Updated: 2021/01/04 12:25:01 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	int		totallen;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	totallen = ft_strlen(s1) + ft_strlen(s2);
	c = (char*)malloc(sizeof(char) * (totallen + 1));
	if (!c)
		return (NULL);
	while (*s1 != '\0')
	{
		*(c + i) = *s1;
		++s1;
		i++;
	}
	while (*s2 != '\0')
	{
		*(c + i) = *s2;
		++s2;
		i++;
	}
	*(c + i) = '\0';
	return (c);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (0);
	while (*(s1 + i) != '\0')
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

char	*biggerstart(void)
{
	char	*c;

	c = (char*)malloc(sizeof(char) * 1);
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
	c = (char*)malloc(sizeof(char) * (len + 1));
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
