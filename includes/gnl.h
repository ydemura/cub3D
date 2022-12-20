/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:49:10 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:09:53 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "../libft/libft.h"
# include "error_handling.h"

typedef struct s_gnl
{
	int		res;
	char	*temp;
	int		len;
	int		conter;
	char	c;
}				t_gnl;

int		exam_get_next_line(int fd, char **line);

#endif /* gnl_h */
