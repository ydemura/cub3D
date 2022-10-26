//
//  colours.c
//  tests
//
//  Created by Yuliia Demura on 4/22/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "colours.h"
#include "libft.h"

int		str_roller(char *str, t_header_info *head)
{
	int i;

	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == ',')
		i++;
	else
		head->errors_parsing = ERR_COLOUR;
	return (i);
}

void	tail_check(char *str, t_header_info *head)
{
	while (*str != '\0')
    {
        if (*str == ' ' || *str == '\t')
            str++;
        else
		{
			head->errors_parsing = ERR_COLOUR;
			return ;
		}    
    }
}

int color_maker(int red,  int green,  int blue, t_header_info *head)
{
	int transperant;

	transperant = 0;
	if ((red >= 0 && red <= 255) && (green >= 0 && green <= 255)
        && (blue >= 0 && blue <= 255))
		return (transperant << 24 | red << 16 | green << 8 | blue);
	else
		head->errors_parsing = ERR_COLOUR;
	return (-1);
}

int 	number_collection(char *str, t_header_info *head, char c, int *n_array)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (ft_isdigit(*str) == 1)
		n_array[0] = ft_atoi(str);
	str += str_roller(str, head);
	while (*str == ' ' || *str == '\t')
		str++;
	if (ft_isdigit(*str) == 1)
		n_array[1] = ft_atoi(str);
	str += str_roller(str, head);
	while (*str == ' ' || *str == '\t')
		str++;
	if (ft_isdigit(*str) == 1)
		n_array[2] = ft_atoi(str);
	while (ft_isdigit(*str) == 1)
		str++;
	tail_check(str, head);
	if (c == 'C')
		head->rgb_ceiling = color_maker(n_array[0], n_array[1], n_array[2], head);
	if (c == 'F')
		head->rgb_floor = color_maker(n_array[0], n_array[1], n_array[2], head);
	return (0);
}

int color_check_collection(t_header_info *head, char *str)
{
    int n_array[3];
    int *ptr_array;
    ptr_array = n_array;
    
	if ( *str == 'C' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
	{
		number_collection(str + 1, head, 'C', ptr_array);
		if (head->errors_parsing == NO_ERROR)
			head->flags.flag_c++;
	}
	else if ( *str == 'F' && (*(str + 1) == ' ' || *(str + 1) == '\t'))
	{
		number_collection(str + 1, head, 'F', ptr_array);
		if (head->errors_parsing == NO_ERROR)
			head->flags.flag_f++;
	}
	else
		head->errors_parsing = ERR_ELEMENT_IDENTIFIER;
	if (head->errors_parsing == NO_ERROR)
		return (0);
	else
		return (1);
}
