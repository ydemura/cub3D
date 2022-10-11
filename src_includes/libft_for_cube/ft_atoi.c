/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/22 09:04:16 by ydemura       #+#    #+#                 */
/*   Updated: 2020/08/22 09:55:08 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int n;
	int res;

	i = 0;
	while (str[i] == 32 || (str[i] >= 8 && str[i] <= 14))
		i++;
	n = 1;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res > (2147483648 / 10) && n == -1)
			return (-1); //was 0, adjusted for cube
		if (res > (2147483647 / 10))
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * n);
}
