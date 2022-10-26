//
//  textures.c
//  cubic
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "textures.h"
#include "colours.h"
#include "resolution.h"
#include "libft.h"

char     *collect_path_new(char *str, t_header_info *head)
{
    char *path_str = NULL;
	int i;
	
	i = 0;
	
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '.' && str[i + 1] == '/')
		path_str = ft_strdup((const char *)str + i);
	
	if (path_str == NULL)
		head->errors_parsing = ERR_MALLOC;
	
	//cant check the tail of path as it can be part of path lel
    return (path_str);
}

void	find_s_identifier(char *str, t_header_info *head)
{
	if (*str == 'S' && *(str + 1) == 'O')
    {
		head->texture_so_file = collect_path_new(str + 2, head);
		head->flags.flag_s++;
    }
	else if (*str == 'S')
    {
		head->texture_sprite_file = collect_path_new(str + 1, head);
		head->flags.flag_sp++;
    }
}

 void	find_identifier(char *str, t_header_info *head)
{
	if (*str == 'N' && *(str + 1) == 'O')
    {
		head->texture_no_file = collect_path_new(str + 2, head);
		head->flags.flag_n++;
    }
	else if (*str == 'W' && *(str + 1) == 'E')
    {
		head->texture_we_file = collect_path_new(str + 2, head);
		head->flags.flag_w++;
    }
	else if (*str == 'E' && *(str + 1) == 'A')
    {
		head->texture_ea_file = collect_path_new(str + 2, head);
		head->flags.flag_e++;
    }
	else if (*str == 'S')
		find_s_identifier(str, head);
}

int    error_check_str_and_collect_path(char *s, t_header_info *head)
{
    int i;
    
    i = 0;
	if ((s[i] == 'N' && s[i + 1] == 'O') || (s[i] == 'W' && s[i + 1] == 'E') ||
        (s[i] == 'E' && s[i + 1] == 'A') || (s[i] == 'S' && s[i + 1] == 'O'))
		i += 2;
	else if (s[i] == 'S')
		i++;
	else
		return (head->errors_parsing = ERR_ELEMENT_IDENTIFIER);
	if (s[i] == ' ' || s[i] == '\t')
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
	}
	else
		return (head->errors_parsing = ERR_ELEMENT);
	if (s[i] == '.' && s[i + 1] == '/')
		find_identifier(s, head);
	else
		return (head->errors_parsing = ERR_ELEMENT_IDENTIFIER);
	return (0);
}
