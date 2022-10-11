//
//  find element.c
//  tests
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"

char     *collect_path(char *str)
{
    int i;
    int j;
    char *path_str;
    int len;
    
    i = 0;
    j = 0;
    len = 0;
    while (str[i] != '.')
        i++;
    len = ft_strlen(str + i);
    path_str = malloc((len + 1) * sizeof(char));
    if (path_str == NULL)
        return (NULL);
    path_str[len] = '\0';
    while (str[i] != '\0')
    {
        path_str[j] = str[i];
        i++;
        j++;
    }
    if (str != NULL)
        free(str);
    
    return (path_str);
}


int     find_element(t_header_info *head, char *str)
{
    int i;
    
    i = 0;
    if (str[i] == 'N' && str[i + 1] == 'O' && str[i + 2] == '.' && str[i + 3] == '/')
    {
        head->texture_no_file = collect_path(str);
        head->flag_n++;
    }
    else if (str[i] == 'E' && str[i + 1] == 'A' && str[i + 2] == '.' && str[i + 3] == '/')
    {
        head->texture_ea_file = collect_path(str);
        head->flag_e++;
    }
    else if (str[i] == 'W' && str[i + 1] == 'E' && str[i + 2] == '.' && str[i + 3] == '/')
    {
        head->texture_we_file = collect_path(str);
        head->flag_w++;
    }
    else if (str[i] == 'S' && str[i + 1] == 'O' && str[i + 2] == '.' && str[i + 3] == '/')
    {
        head->texture_so_file = collect_path(str);
        head->flag_s++;
    }
    else if (str[i] == 'S' && str[i + 1] == '.' && str[i + 2] == '/')
    {
        head->texture_sprite_file = collect_path(str);
        head->flag_sp++;
    }
        
    
    else if (str[i] == 'F')
    {
        head->flag_f++;
    }
    
    else if (str[i] == 'C')
    {
        head->flag_c++;
    }
    else if (str[i] == 'R' && (str[i + 1] == ' ' || str[i + 1] == '\t'))
    {
        if (collect_resolution(head, str) == 1)
            return (1);
        else
            head->flag_r++;
    }
    else
    {
//        head->error->wrong_element_identifier = 1;
        return (1);
    }

    
    return (0);
}
