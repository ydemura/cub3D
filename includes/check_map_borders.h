//
//  check_map_borders.h
//  cubic_xcode_part
//
//  Created by Julia Demura on 25/10/2022.
//  Copyright © 2022 Yuliia Demura. All rights reserved.
//

#ifndef check_map_borders_h
#define check_map_borders_h

typedef struct
{
	int		ri;
	int		ci;
	int		rn;
	int		cn;
	char	**arr;
	char	c;
	int		next_line_flag;
}			t_grid;

int	check_map_for_boarders(t_grid *grid);

#endif /* check_map_borders_h */
