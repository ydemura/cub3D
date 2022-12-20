/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemura <ydemura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:47:00 by yuliia            #+#    #+#             */
/*   Updated: 2022/12/08 15:09:35 by ydemura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

typedef enum e_boolean
{
	TRU = 1,
	FLS = 0
}			t_boolean;

typedef enum e_error_handling
{
	NO_ERROR = 0,
	ERR_ELEMENT_IDENTIFIER = 101,
	ERR_ELEMENT = 102,
	ERR_INCOMPLETE_INFORMATION = 103,
	ERR_DUPLICATE_ELEMENT = 104,
	ERR_RESOLUTION = 105,
	ERR_COLOUR = 106,
	ERR_MAP = 107,
	ERR_MALLOC = 108,
	ERR_OPEN = 109,
	ERR_CLOSE = 110,
	ERR_READ = 111,
	ERR_EXTENTION = 112
}			t_error_handling;

void	error_message_exit(t_error_handling err);

#endif /* error_handling_h */
