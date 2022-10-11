/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: julia <julia@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:51:43 by julia         #+#    #+#                 */
/*   Updated: 2020/10/26 19:31:16 by julia         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned	int i;
	signed		int difference;

	i = 0;
	while (((unsigned char)s1[i] != '\0' ||
			(unsigned char)s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			difference = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (difference);
		}
		i++;
	}
	return (0);
}
