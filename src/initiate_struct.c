//
//  initiate_struct.c
//  tests
//
//  Created by Yuliia Demura on 19/04/2021.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "initiate_struct.h"
#include "form_gamestate.h"

void    initiate_flags(t_flags *flags)
{
    flags->flag_n = 0;
    flags->flag_e = 0;
    flags->flag_s = 0;
    flags->flag_sp = 0;
    flags->flag_w = 0;
    flags->flag_f = 0;
    flags->flag_c = 0;
    flags->flag_r = 0;
    flags->all_flags_collected = 0;
}

void initiate_header_srtuct(t_header_info *head)
{
    t_flags flags;

    head->errors_parsing = NO_ERROR;
    initiate_flags(&flags);
    head->flags = flags;
}
