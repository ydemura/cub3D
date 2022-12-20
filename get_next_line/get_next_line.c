/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: catalina <catalina@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 19:44:42 by catalina      #+#    #+#                 */
/*   Updated: 2022/10/03 16:38:56 by adoner        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_digit	check_newline(char *old_info, int inside_value)
{
	int		i;
	t_digit	arr;

	arr.result = 0;
	arr.inside_while = inside_value;
	arr.where = 0;
	if (!old_info)
		return (arr);
	i = 0;
	while (old_info[i] != '\0')
	{
		arr.where = i;
		if (old_info[i] == '\n')
		{
			arr.result = 1;
			return (arr);
		}
		i++;
	}
	return (arr);
}

char	*add_old_string(char *old_string, char *string)
{
	char	*tmp;

	if (!old_string)
		old_string = ft_strdup("");
	tmp = ft_strjoin(old_string, string);
	free(old_string);
	return (tmp);
}

char	*update_old_string(char *old_string)
{
	char	*tmp;
	t_digit	arr_digit;

	if (!old_string)
		return (NULL);
	arr_digit = check_newline(old_string, 0);
	if (arr_digit.result == 1)
	{
		tmp = ft_substr(old_string, arr_digit.where + 1,
				ft_strlen(old_string + arr_digit.where));
	}
	else
		tmp = NULL;
	free(old_string);
	return (tmp);
}

char	*line_load(char *old_string)
{
	char	*line;

	if (!old_string)
		return (NULL);
	if (old_string[check_newline(old_string, 0).where] == '\n')
		line = ft_substr(old_string, 0, check_newline(old_string, 0).where);
	else
		line = ft_strdup(old_string);
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char	*old_string;
	int			result;
	char		string[100 + 1];
	t_digit		arr_digit;

	if (fd >= MAX_FD || fd < 0
		|| line == NULL || read(fd, string, 0) < 0)
		return (-1);
	arr_digit = check_newline(old_string, 0);
	result = 1;
	while (result > 0 && arr_digit.result == 0
		&& !(!old_string && arr_digit.inside_while == 1))
	{
		result = read(fd, string, 100);
		string[result] = '\0';
		arr_digit = check_newline(string, 1);
		old_string = add_old_string(old_string, string);
	}
	*line = line_load(old_string);
	old_string = update_old_string(old_string);
	if (!line || (old_string == NULL && result != 0))
		return (-1);
	if (result != 0)
		return (1);
	return (0);
}
