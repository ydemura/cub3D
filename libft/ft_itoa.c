/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 13:32:23 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:45:05 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	len_find(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*send_zero(void)
{
	char	*a;

	a = (char *)malloc(2);
	if (!a)
		return (NULL);
	*(a + 0) = '0';
	*(a + 1) = '\0';
	return (a);
}

static	char	*send_max(void)
{
	int		i;
	char	*a;
	int		nmbr;

	nmbr = 214748364;
	i = 11;
	a = (char *)malloc(12);
	if (!a)
		return (NULL);
	*(a + i) = '\0';
	*(a + i - 1) = '8';
	i -= 2;
	while (i > 0)
	{
		*(a + i) = (nmbr % 10) + '0';
		nmbr /= 10;
		i--;
	}
	*(a + i) = '-';
	return (a);
}

static	char	*convert(int control, int len, int n)
{
	char	*a;

	a = (char *)malloc(len + 1);
	if (!a)
		return (NULL);
	*(a + len) = '\0';
	while (n > 0)
	{
		len--;
		*(a + len) = (n % 10) + '0';
		n /= 10;
	}
	if (control == -1)
	{
		len--;
		*(a + len) = '-';
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int	len;
	int	control;

	if (n == 0)
		return (send_zero());
	if (n == -2147483648)
		return (send_max());
	control = 1;
	len = len_find(n);
	if (n < 0)
	{
		len++;
		n *= -1;
		control = -1;
	}
	return (convert(control, len, n));
}
