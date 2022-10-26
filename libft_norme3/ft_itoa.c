/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 09:04:16 by ydemura       #+#    #+#                 */
/*   Updated: 2021/10/01 01:43:40 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	len_counter(int n)
{
	int	n_check;
	int	len;

	len = 0;
	n_check = n;
	if (n < 0)
	{
		n_check = -n;
		len++;
	}
	while (n_check > 0)
	{
		n_check = n_check / 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

static char	*ft_putnmbr(char *s, int n, int i)
{
	if (n < 0)
	{
		s[i] = '-';
		i++;
		n = n * -1;
	}
	if (n / 10 != 0)
	{
		ft_putnmbr(s, (n / 10), i + 1);
	}
	s[i] = (n % 10) + '0';
	return (s);
}

static char	*ft_strrev(char *s)
{
	int		len;
	char	temp;
	int		i;

	i = 0;
	len = ft_strlen(s);
	if (s[i] == '-')
	{
		i++;
	}
	while (i < len)
	{
		temp = s[i];
		s[i] = s[len - 1];
		s[len - 1] = temp;
		i++;
		len--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;

	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	len = len_counter(n);
	s = (char *)malloc((len + 1) * sizeof(char));
	if (s == NULL)
	{
		return (NULL);
	}
	s[len] = '\0';
	i = 0;
	s = ft_putnmbr(s, n, i);
	s = ft_strrev(s);
	return (s);
}
