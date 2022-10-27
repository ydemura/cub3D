//
//  gnl.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef gnl_h
#define gnl_h

#include "libft.h"
#include "error_handling.h"

typedef struct s_gnl
{
	int		res;
	char	*temp;
	int		len;
	int		conter;
	char	c;
}				t_gnl;

int		exam_get_next_line(int fd, char **line);

#endif /* gnl_h */
