//
//  clean_str.c
//  tests
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"

char*    check_r_c_f_while_clean_str(char *str, t_header_info *head, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == c)
            return (str + i);
        else
            break ;
    }
    return (str); //return bullshit in case of not r/c/f so find element will catch wrong element identifier
}

int identifier_check(char *str, t_header_info *head)
{
    int i;
    
    i = 0;
    if (str[i] == 'N' && str[i + 1] == 'O')
        return (0);
    else if (str[i] == 'E' && str[i + 1] == 'A')
        return (0);
    else if (str[i] == 'W' && str[i + 1] == 'E')
        return (0);
    else if (str[i] == 'S' && str[i + 1] == 'O')
        return (0);
    else if (str[i] == 'S')
        return (0);
        
    
    else if (str[i] == 'F')
        return (0);
    
    else if (str[i] == 'C')
        return (0);
    else if (str[i] == 'R')
        return (0);
//    else
//    {
//        head->error->wrong_element_identifier = 1;
//        return (1);
//    }
    return (0);
}

char *strcpy_without_spaces(int len, char *str)
{
    char *clean_str;
    int i;
    int j;

    j = 0;
    clean_str = malloc((len + 1) * sizeof(char));
    if (clean_str == NULL)
        return (NULL);
    clean_str[len] = '\0';
    i = 0;
    while (str[j] != '\0')
    {
        if (str[j] == ' ' || str[j] == '\t')
            j++;
        else
        {
            clean_str[i] = str[j];
            j++;
            i++;
        }
    }
    return (clean_str);
}


char *clean_str(char *str, t_header_info *head)
{
    char *clean_str;
    int len;
    int i;
    int j;
    
    i = 0;
    j = 0;
    len = 0;
    
    while (str[i] != '\0')
    {
        if (str[i] == 'R')
            return (check_r_c_f_while_clean_str(str, head, 'R'));
        if (str[i] != ' ' && str[i] != '\t')
            len++;
        i++;
    }
    clean_str = strcpy_without_spaces(len, str);
//    if (clean_str == NULL)
//        head->error->malloc_crush = 1;
    if (str != NULL)
        free(str);
    return(clean_str);
}
