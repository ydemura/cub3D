//
//  exam_gnl.c
//  get_next_line
//
//  Created by Julia on 24.01.2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

//#include "header_all.h"
# include <unistd.h>
# include <stdlib.h>

char *m_realloc(char *str, int len)
{
	int i;
	char *new_str;
	i = 0;
	new_str = malloc((len + 1) * sizeof(char));
	while (str[i] != '\0' && i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	free (str);
	new_str[len] = '\0';
	return (new_str);
}

int		exam_get_next_line(int fd, char **line)
{
	*line = NULL;
	int res = 1;
	char *temp;
	int len = 10;
	int conter = 0;
	temp = malloc((len + 1) * sizeof(char));
	char c;
	c = '\0';
	temp[len] = '\0';

	if (!line)
		return (-1);
	while (c != '\n' && res != 0)
	{
		res = (int)read(fd, &c, 1);
		if (*temp == '\0' && c == '\n')
			return (res);
		if (res == -1)
			return (-1);
		temp[conter] = c;
		conter++;
		if (conter == len)
		{
			len = len * 2;
			temp = m_realloc(temp, len);
		}
	}
	temp = m_realloc(temp, conter);
	temp[conter - 1] = '\0';
	*line = temp;
	return (res);
}
