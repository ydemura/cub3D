//
//  main.c
//  ali-repo-cube
//
//  Created by Julia Demura on 23/11/2022.
//

#include <stdio.h>

#include "parsing_gamestate.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, const char *argv[])
{
	t_parsing_result	parsing_result;

	parsing_result = parsing(argv, argc);
	
	//do your tghing here :)
	return (0);
}
