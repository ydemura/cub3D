/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 11:19:34 by adoner        #+#    #+#                 */
/*   Updated: 2022/12/08 21:47:09 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	control_func(char const *s1, char const *set, int x, int i)
{
	int	control;

	control = 0;
	while (*(set + x) != '\0')
	{
		if (*(set + x) == *(s1 + i - 1))
		{
			control++;
			break ;
		}
		x++;
	}
	return (control);
}

static	int	endcheck(char const *s1, char const *set, int old_i)
{
	int	i;
	int	x;
	int	control;

	control = 0;
	i = ft_strlen(s1);
	x = 0;
	while (*(s1 + i - 1) != '\0')
	{
		if (old_i < i)
		{
			control = control_func(s1, set, x, i);
			if (control == 0)
				break ;
			x = 0;
			i--;
			control = 0;
		}
		else
			break ;
	}
	return (ft_strlen(s1) - i);
}

static	int	first_check(char const *s1, char const *set)
{
	int	control;
	int	x;
	int	i;

	x = 0;
	i = 0;
	control = 0;
	while (*(s1 + i) != '\0')
	{
		while (*(set + x) != '\0')
		{
			if (*(set + x) == *(s1 + i))
			{
				control++;
				break ;
			}
			x++;
		}
		if (control == 0)
			break ;
		x = 0;
		i++;
		control = 0;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*s;
	unsigned int	first;
	unsigned int	end;
	int				i;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return ((char *)s1);
	i = 0;
	first = first_check(s1, set);
	end = endcheck(s1, set, first);
	s = (char *)malloc(ft_strlen(s1) - first - end + 1);
	if (!s)
		return (NULL);
	while (first < (ft_strlen(s1) - end))
	{
		*(s + i) = *(s1 + first);
		first++;
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
