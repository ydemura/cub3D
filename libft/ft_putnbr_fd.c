/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 16:39:09 by adoner        #+#    #+#                 */
/*   Updated: 2021/02/24 22:48:10 by catalina      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int	check(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	else if (nb < 0)
	{
		nb = nb * (-1);
		write(fd, "-", 1);
	}
	else if (nb == 0)
		write(fd, "0", 1);
	return (nb);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			realint;
	int				nb2;
	long double		i;
	int				aa;

	i = 1;
	n = check(n, fd);
	nb2 = n;
	while (n != 0 && n != -2147483648)
	{
		n /= 10;
		i = i * 10;
	}
	while (i >= 10 && n != -2147483648)
	{
		i /= 10;
		aa = (nb2 / i);
		nb2 -= aa * i;
		realint = aa + '0';
		write(fd, &realint, 1);
	}
}
