/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ydemura <ydemura@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 13:12:46 by ydemura       #+#    #+#                 */
/*   Updated: 2021/10/01 01:57:34 by ydemura       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_memory
{
	int		res;
	int		status;
	char	left[BUFFER_SIZE + 1];
}			t_memory;

int					ft_strlen(const char *str);
char				*ft_strdup_till_n(const char *s1, int len,
						t_memory *memory);
void				after_n_memcpy(char *left, char *temp, unsigned int n);
char				*ft_realloc(char **line, int new_len, t_memory *memory);
char				*ft_strjoin_realloc(char *s1, t_memory *memory);
int					return_management(char **line, t_memory *memory);
int					cut_line_and_left(char **line, t_memory *memory,
						char *temp);
int					find_cut_new_line(t_memory *memory, char **line);
int					ft_read(int fd, t_memory *memory, char **line);
int					get_next_line(int fd, char **line);

#endif
