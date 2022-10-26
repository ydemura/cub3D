//
//  initiate_map_size.c
//  tests
//
//  Created by Yuliia Demura on 03/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "initiate_map_size.h"
#include "libft.h"
#include "gnl.h"
#include "form_header_structure.h"
#include <fcntl.h>
#include <unistd.h>

int	initiate_map_struct_open_file(const char *file_name, t_map_size *map_size)
{
    int fd;

    map_size->len_cols = 0;
    map_size->len_rows = 0;
    map_size->map_error = 0;
    map_size->player_flag = 0;
    map_size->errors_parsing = NO_ERROR;
    
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        map_size->errors_parsing = ERR_OPEN;
    return (fd);
}

int check_if_str_is_valid_map(char *str, t_map_size *map_size)
{
    while (*str != '\0')
    {
        if (*str == '1' || *str == '0' || *str == ' ' || *str == '2')
            str++;
//        else if (*str == '\n')
//            str++; //my gnl give me NULL in case of pure \n
        else if (*str == 'N' || *str == 'S' || *str == 'E' || *str == 'W')
        {
            map_size->player_flag++;
            str++;
        }
        else
            map_size->errors_parsing = ERR_MAP;
    }
    if (map_size->player_flag > 1)
        map_size->errors_parsing = ERR_MAP;
    
    return (map_size->errors_parsing);
}

int count_map_size_part_two(char *str, t_map_size *map_size)
{
    
    if (str == NULL || *str == '\0')
        return (map_size->errors_parsing = ERR_MAP);
    if (check_if_str_is_valid_map(str, map_size) == 0)
    {
        if (map_size->len_cols < ft_strlen(str))
            map_size->len_cols = ft_strlen(str);
        map_size->len_rows++;
    }
    else
        map_size->errors_parsing = ERR_MAP;
    
    return (map_size->errors_parsing);
}

int close_file(t_map_size *map_size, int fd)
{
    if (close(fd) < 0)
        map_size->errors_parsing = ERR_CLOSE;
    
    return (map_size->errors_parsing);
}

t_map_size initiate_map_size(const char *file_name)
{
    int fd;
    int res;
    char *str;
    int str_found;
	t_map_size map_size;

    res = 1;
    str_found = 0;
    fd = initiate_map_struct_open_file(file_name, &map_size);
    while (res > 0 && map_size.errors_parsing == NO_ERROR)
    {
        res = exam_get_next_line(fd, &str);
        if (res == -1)
			map_size.errors_parsing = ERR_READ;
        if (res <= 0)
            break ;
        if (str_found == 0 && check_if_string_is_map(str) == 1)
            str_found = 1;
        else if (str_found == 1)
            count_map_size_part_two(str, &map_size);
    }
    close_file(&map_size, fd);
	return (map_size);
}




//        if ((str != NULL && *str != '\0') && str_found == 1)
//            count_map_size_part_two(str, map_size);
        
        
//        else if ((str == NULL || *str == '\0') && str_found == 1)
//            return (map_size->errors_parsing = ERR_MAP);


//int     skip_head(char *file_name, t_map_size *map_size)
//{
//    int fd;
//    int res;
//    char *str;
//
//    res = 1;
//    fd = open(file_name, O_RDONLY);
//    if (fd == -1)
//        printf("not opened_in_count_map_size\n");
//    while (res > 0)
//    {
//        res = exam_get_next_line(fd, &str);
//        if (res == -1)
//            return (map_size->errors_parsing = ERR_READ);
//        if (str != NULL)
//        {
//            if (check_if_string_is_map(str) == 1)
//            {
//                map_size->len_cols = ft_strlen(str);
//                map_size->len_rows++;
//                break ;
//            }
//        }
//    }
//    return (fd);
//}
//
//int        count_map_size(char *file_name, t_map_size *map_size)
//{
//	int len_current_col;
//    int fd;
//    char c;
//
//    initiate_map_struct(map_size);
//    len_current_col = 0;
//    fd = skip_head(file_name, map_size);
//    while (read(fd, &c, 1) > 0)
//    {
//        if (c != '\n')
//        {
//            len_current_col++;
//            map_size->map_error = 0;
//        }
//        if (c == '\n') //or else
//        {
//            map_size->len_rows++;
//            if (map_size->len_cols < len_current_col)
//                map_size->len_cols = len_current_col;
//            len_current_col = 0;
//            map_size->map_error++;
//            if (map_size->map_error > 1)
//                return (map_size->errors_parsing = ERR_MAP);
//        }
//    }
//    if (close(fd) < 0)
//        return (map_size->errors_parsing = ERR_CLOSE);
//    return (0);
//}
