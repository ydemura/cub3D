/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: adoner <adoner@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 16:31:36 by adoner        #+#    #+#                 */
/*   Updated: 2020/11/16 11:48:55 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (!(s == NULL))
	{
		while (*s != '\0')
		{
			write(fd, s, 1);
			s++;
		}
	}
	write(fd, "\n", 1);
}
