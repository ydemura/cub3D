//
//  new_error_handling.c
//  tests
//
//  Created by Yuliia Demura on 4/22/21.
//  Copyright © 2021 Yuliia Demura. All rights reserved.
//

#include "header_all.h"

int 	error_handling(t_error_handling err)
{
	printf("error code: %i\n", err);
	if (err == ERR_ELEMENT_IDENTIFIER)
		printf("wrong element identifier detected\n");
	else if (err == ERR_ELEMENT)
		printf("wrong element detected\n");
	else if (err == ERR_INCOMPLETE_INFORMATION)
		printf("unable to collect all required information\n");
	else if (err == ERR_DUPLICATE_ELEMENT)
		printf("detected duplicated element\n");
	else if (err == ERR_RESOLUTION)
		printf("error in resolution\n");
	if (err == ERR_COLOUR)
		printf("error in colours information\n");
    if (err == ERR_MAP)
        printf("error in map representation\n");
    
	else if (err == ERR_MALLOC)
		printf("malloc crushed\n");
    else if (err == ERR_OPEN)
        printf("open crushed\n");
    else if (err == ERR_CLOSE)
        printf("close crushed\n");
    else if (err == ERR_READ)
        printf("read crushed\n");
	return (err);
}
