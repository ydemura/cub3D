/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliia <yuliia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:51:59 by yuliia            #+#    #+#             */
/*   Updated: 2022/10/31 19:52:00 by yuliia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handling.h"
#include <stdio.h>
#include <stdlib.h>

void	error_message_exit(t_error_handling err)
{
	printf("error: ");
	if (err == ERR_ELEMENT_IDENTIFIER)
		printf("wrong element identifier detected\n");
	else if (err == ERR_ELEMENT)
		printf("wrong element detected\n");
	else if (err == ERR_INCOMPLETE_INFORMATION)
		printf("unable to collect all required information\n");
	else if (err == ERR_DUPLICATE_ELEMENT)
		printf("detected duplicated element\n");
	else if (err == ERR_RESOLUTION)
		printf("error in resolution\n");
	if (err == ERR_COLOUR)
		printf("error in colours information\n");
	if (err == ERR_MAP)
		printf("error in map representation\n");
	else if (err == ERR_MALLOC)
		printf("malloc crushed\n");
	else if (err == ERR_OPEN)
		printf("open crushed\n");
	else if (err == ERR_CLOSE)
		printf("close crushed\n");
	else if (err == ERR_READ)
		printf("read crushed\n");
	exit(EXIT_FAILURE);
}
