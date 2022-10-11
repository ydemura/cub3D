//
//  read_map_addition.c
//  cubic_xcode_part
//
//  Created by Yuliia Demura on 5/4/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"

int find_if_error_is_identifier(char c, t_header_info *head)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F'|| c == 'C' || c == 'R')
    {
        if (head->flags.all_flags_collected == 1)
            head->errors_parsing = ERR_DUPLICATE_ELEMENT;
        else
            head->errors_parsing = ERR_INCOMPLETE_INFORMATION;
    }
    return (0);
}

int check_set_of_char(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (0);
    else if (c == ' ' || c == '0' || c == '1' || c == '2')
        return (0);
    else if (c == '\n')
        return (0);
    else
        return (1);
}
