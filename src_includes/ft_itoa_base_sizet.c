/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: julia <julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 21:06:19 by julia         #+#    #+#                 */
/*   Updated: 2021/01/08 21:06:20 by julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header_all.h"

static	int	len_counter_base(size_t n, int base)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / base;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

void		ft_itoa_base(size_t n, char *s, int base, char set)
{
	int	len;
	int i;
	const char *digit_set;

	len = len_counter_base(n, base);
	i = 0;
	s[len] = '\0';
	if (set == 'H')
		digit_set = "0123456789ABCDEF";
	else if (set == 'h')
		digit_set = "0123456789abcdef";
	else
		digit_set = "0123456789";
	len--;
	while (len + 1 > 0)
	{
		s[len] = digit_set[n % base];
		len--;
		n = n / base;
	}
}
