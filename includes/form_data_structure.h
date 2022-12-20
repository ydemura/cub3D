/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_data_structure.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:48:18 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:09:42 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_DATA_STRUCTURE_H
# define FORM_DATA_STRUCTURE_H

# include "initiate_data.h"
# include "initiate_map_size.h"

int	form_data_structure(int fd, t_map_size *mp_size, t_data *data);
int	is_string_map(char *str);

#endif /* form_data_structure.h */
