//
//  resolution.c
//  tests
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "resolution.h"
#include "libft.h"

int space_skipper(t_data *data, char *str)
{
    int i;

    i = 0;
    if (str[i] == ' ' || str[i] == '\t')
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
    }
    else
        return (data->err = ERR_RESOLUTION);
    return (i);
}

int        get_number_for_x_and_y(char *str, t_data *data)
{
    int i;
    int check_space;

    i = 0;
    check_space = space_skipper(data, str);
    if (data->err == ERR_RESOLUTION)
        return (-1);
    else
        i = i + check_space;
    if (data->x_render_size == 0)
        data->x_render_size = ft_atoi(str);
    else
        data->y_render_size = ft_atoi(str);
    
    if (data->x_render_size < 0 || data->y_render_size < 0)
    {
        data->err = ERR_RESOLUTION;
        return (-1);
    }
    while (ft_isalnum(str[i]))
        i++;
    return (i);
}

int     collect_resolution(t_data *data, char *str)
{
    int roll_str_find_resolution_number;

    roll_str_find_resolution_number = 0;
    roll_str_find_resolution_number = get_number_for_x_and_y(str, data);
    if (roll_str_find_resolution_number == -1)
        return (1);
    else
        str = str + roll_str_find_resolution_number;
    roll_str_find_resolution_number = get_number_for_x_and_y(str, data);
    if (roll_str_find_resolution_number == -1)
        return (1);
    else
        str = str + roll_str_find_resolution_number;
    while (*str != '\0')
    {
        if (*str == ' ' || *str == '\t')
            str++;
        else
            return (data->err = ERR_RESOLUTION);
    }
    if (data->y_render_size <= 0 || data->x_render_size <= 0)
        return (data->err = ERR_RESOLUTION);
    return (0);
}
