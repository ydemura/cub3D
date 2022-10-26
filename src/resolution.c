//
//  resolution.c
//  tests
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "resolution.h"
#include "libft.h"

int space_skipper(t_header_info *head, char *str)
{
    int i;

    i = 0;
    if (str[i] == ' ' || str[i] == '\t')
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
    }
    else
        return (head->errors_parsing = ERR_RESOLUTION);
    return (i);
}

int        get_number_for_x_and_y(char *str, t_header_info *head)
{
    int i;
    int check_space;

    i = 0;
    check_space = space_skipper(head, str);
    if (head->errors_parsing == ERR_RESOLUTION)
        return (-1);
    else
        i = i + check_space;
    if (head->x_render_size == 0)
        head->x_render_size = ft_atoi(str);
    else
        head->y_render_size = ft_atoi(str);
    
    if (head->x_render_size < 0 || head->y_render_size < 0)
    {
        head->errors_parsing = ERR_RESOLUTION;
        return (-1);
    }
    while (ft_isalnum(str[i]))
        i++;
    return (i);
}

int     collect_resolution(t_header_info *head, char *str)
{
    int roll_str_find_resolution_number;

    roll_str_find_resolution_number = 0;
    roll_str_find_resolution_number = get_number_for_x_and_y(str, head);
    if (roll_str_find_resolution_number == -1)
        return (1);
    else
        str = str + roll_str_find_resolution_number;
    roll_str_find_resolution_number = get_number_for_x_and_y(str, head);
    if (roll_str_find_resolution_number == -1)
        return (1);
    else
        str = str + roll_str_find_resolution_number;
    while (*str != '\0')
    {
        if (*str == ' ' || *str == '\t')
            str++;
        else
            return (head->errors_parsing = ERR_RESOLUTION);
    }
    if (head->y_render_size <= 0 || head->x_render_size <= 0)
        return (head->errors_parsing = ERR_RESOLUTION);
    return (0);
}
