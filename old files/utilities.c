//utilities.c

//to store all additional f-s
//01.04.2021

#include "header_all.h"

void	write_char(char c)
{
	write(1, &c, 1);
}

void	write_str(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write_char(str[i]);
		i++;
	}
}
