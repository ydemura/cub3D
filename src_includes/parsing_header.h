//
//  parsing_header.h
//  cubic_xcode_part
//
//  Created by Yuliia Demura on 5/4/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#ifndef parsing_header_h
#define parsing_header_h


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef enum    e_kind
{
    KIND_FLOOR = '0',
    KIND_WALL = '1',
    KIND_OBJECT = '2',
    KIND_EMPTY = ' ',
    KIND_END_MAP = 255,
}                 t_kind;

typedef enum     e_error_handling
{
    NO_ERROR = 0,
    
    ERR_ELEMENT_IDENTIFIER = 101,
    ERR_ELEMENT = 102,
    ERR_INCOMPLETE_INFORMATION = 103,
    ERR_DUPLICATE_ELEMENT = 104,
    ERR_RESOLUTION = 105,
    ERR_COLOUR = 106,
    ERR_MAP = 107,
    
    ERR_MALLOC = 108,
    ERR_OPEN = 109,
    ERR_CLOSE = 110,
    ERR_READ = 111
    
}                t_error_handling;

typedef struct  s_flags
{
    int flag_n;
    int flag_s;
    int flag_e;
    int flag_w;
    int flag_sp;
    int flag_f;
    int flag_c;
    int flag_r;
    int all_flags_collected;
}           t_flags;


#endif /* parsing_header_h */
