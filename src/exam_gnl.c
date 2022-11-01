/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:52:05 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:52:06 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <unistd.h>
#include <stdlib.h>

char	*m_realloc(char *str, int len)
{
	int		i;
	char	*new_str;

	i = 0;
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		error_message_exit(ERR_MALLOC);
	while (str[i] != '\0' && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	free (str);
	new_str[len] = '\0';
	return (new_str);
}

void	initiate_gnl_struct(t_gnl *gnl)
{
	gnl->res = 1;
	gnl->len = 10;
	gnl->conter = 0;
	gnl->temp = malloc((gnl->len + 1) * sizeof(char));
	if (gnl->temp == NULL)
		error_message_exit(ERR_MALLOC);
	gnl->c = '\0';
	gnl->temp[gnl->len] = '\0';
}

int	exam_get_next_line(int fd, char **line)
{
	t_gnl	gnl;

	*line = NULL;
	initiate_gnl_struct(&gnl);
	while (gnl.c != '\n' && gnl.res != 0)
	{
		gnl.res = (int)read(fd, &gnl.c, 1);
		if (gnl.res == -1)
			error_message_exit(ERR_READ);
		else if (*gnl.temp == '\0' && gnl.c == '\n')
			return (gnl.res);
		gnl.temp[gnl.conter] = gnl.c;
		gnl.conter++;
		if (gnl.conter == gnl.len)
		{
			gnl.len = gnl.len * 2;
			gnl.temp = m_realloc(gnl.temp, gnl.len);
		}
	}
	gnl.temp = m_realloc(gnl.temp, gnl.conter);
	gnl.temp[gnl.conter - 1] = '\0';
	*line = gnl.temp;
	return (gnl.res);
}
