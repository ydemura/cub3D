/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:43 by ydemura       #+#    #+#                 */
/*   Updated: 2021/10/01 01:53:50 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	return_management(char **line, t_memory *memory)
{
	if (memory->status == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
		return (-1);
	}
	if (memory->status == 1)
	{
		return (1);
	}
	return (0);
}

int	cut_line_and_left(char **line, t_memory *memory, char *temp)
{
	int	n;

	n = 0;
	while (temp[n] != '\0')
	{
		if (temp[n] == '\n')
		{
			*line = ft_strdup_till_n(temp, n, memory);
			if (memory->status == -1)
				return (-1);
			after_n_memcpy(memory->left, temp, n);
			return (1);
		}
		n++;
	}
	return (0);
}

int	find_cut_new_line(t_memory *memory, char **line)
{
	char	*temp;

	temp = ft_strjoin_realloc(*line, memory);
	if (memory->status == -1)
	{
		free(temp);
		return (-1);
	}
	if (cut_line_and_left(line, memory, temp) == 1)
	{
		if (temp != 0)
			free(temp);
		memory->status = 1;
		return (1);
	}
	*line = ft_strdup_till_n(temp, ft_strlen(temp), memory);
	free(temp);
	if (memory->status == -1)
		return (-1);
	*(memory->left) = '\0';
	return (0);
}

int	ft_read(int fd, t_memory *memory, char **line)
{
	memory->res = (int)read(fd, memory->left, BUFFER_SIZE);
	if (memory->res == -1)
	{
		memory->status = -1;
		return (-1);
	}
	if (memory->res == 0)
	{
		memory->left[memory->res] = '\0';
		*line = ft_strjoin_realloc(*line, memory);
		if (!line)
			memory->status = -1;
	}
	memory->left[memory->res] = '\0';
	return (memory->res);
}

int	get_next_line(int fd, char **line)
{
	static t_memory	memory;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	memory.res = 1;
	memory.status = 0;
	*line = NULL;
	while (memory.res > 0)
	{
		if (*(memory.left))
		{
			find_cut_new_line(&memory, line);
			if (memory.status == 1 || memory.status == -1)
				return (return_management(line, &memory));
		}
		else if ((ft_read(fd, &memory, line)) < 0)
		{
			return (return_management(line, &memory));
		}
	}
	return (return_management(line, &memory));
}
