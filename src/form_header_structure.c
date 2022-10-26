//
//  form_header_structure.c
//  tests
//
//  Created by Yuliia Demura on 05/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "form_header_structure.h"
#include "colours.h"
#include "resolution.h"
#include "textures.h"
#include "gnl.h"
#include <stdlib.h>

int 	check_if_string_is_map(char *str)
{
	int i;

	i = 0;
    if (str == NULL)
        return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == ' ' || str[i] == '0' || str[i] == '2')
			i++;
        else if (str[i] == 'N' || str[i] == 'W' || str[i] == 'E' || str[i] == 'S')
            i++;
		else
			return (0); //not map
	}
	return (1); //is map
}

void 	flag_checkup(t_header_info *head)
{
    if (head->flags.flag_w == 1 && head->flags.flag_sp == 1 && head->flags.flag_s == 1 &&
        head->flags.flag_e == 1 && head->flags.flag_n == 1 && head->flags.flag_f == 1 &&
        head->flags.flag_c == 1 && head->flags.flag_r == 1)
	{
        head->flags.all_flags_collected = 1;
	}
	else if (head->flags.flag_w > 1 || head->flags.flag_sp > 1 || head->flags.flag_s > 1 ||
             head->flags.flag_e > 1 || head->flags.flag_n > 1 || head->flags.flag_f > 1 ||
             head->flags.flag_c > 1 || head->flags.flag_r > 1)
	{
        head->flags.all_flags_collected = 2;
		head->errors_parsing = ERR_DUPLICATE_ELEMENT;
	}
    else
        head->flags.all_flags_collected = 0;
}

int   string_handler(char *str, t_header_info *head)
{
	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	if (*str == 'N' || *str == 'W' || *str == 'E' || *str == 'S')
	{
		if (error_check_str_and_collect_path(str, head) == 1)
			return (head->errors_parsing);
	}
	else if (*str == 'R')
	{
		if (collect_resolution(head, str + 1) == 0)
			head->flags.flag_r++;
	}
	else if (*str == 'C' || *str == 'F')
	{
		if (color_check_collection(head, str) == 1)
			return (head->errors_parsing);
	}
	else
		head->errors_parsing = ERR_ELEMENT_IDENTIFIER;
	return (head->errors_parsing);
}

int    pars_buffer(t_header_info *head, char *buff)
{
    if (head->flags.all_flags_collected == 0 && check_if_string_is_map(buff) == 1)
    {
        return (head->errors_parsing = ERR_INCOMPLETE_INFORMATION);
    }
    if (string_handler(buff, head) != 0)
        return (head->errors_parsing);
    flag_checkup(head);
    return (0);
}

int        form_header_structure(int fd, t_header_info *head)
{
	char 	*buff;
	int		res;

	initiate_header_srtuct(head);
	res = 1;
    while (res > 0 && head->flags.all_flags_collected != 1)
	{
        if (head->errors_parsing != NO_ERROR)
			return (head->errors_parsing);
		res = exam_get_next_line(fd, &buff); // ADD original GNL?
		if (buff != NULL)
		{
            pars_buffer(head, buff);
            free(buff);
		}
	}
    if (res == 0 && head->flags.all_flags_collected != 1)
        head->errors_parsing = ERR_INCOMPLETE_INFORMATION;
    if (head->flags.all_flags_collected == 1 && head->errors_parsing == NO_ERROR)
        return (0);
    else
        return (head->errors_parsing);
}
