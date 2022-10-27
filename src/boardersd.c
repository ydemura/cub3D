//boarders.c

//cube3d
//27.10.2022

#include "boarders.h"
#include "initiate_data.h"
#include <stdio.h>

//assume I have map

int	is_there_a_wall(int ir, int ic, int nr, int nc)
{
	int	go_row = ir;
	int go_col = ic;
	int end_row = nr;
	int end_col = nc;
	int wall_found;
	int here = -1;
	
	int grid[8][9]=
	{
		{1,1,1,1,1,1,1,1,1},
		{3,3,3,1,1,1,0,0,0},
		{1,1,1,1,0,0,0,0,1},
		{1,1,0,0,0,0,1,1,1},
		{3,1,0,0,0,0,1,1},
		{1,1,0,0,0,'N',1,1,1},
		{1,0,0,0,1,1,1,1,1},
		{1,1,1,1,1,1,3,3,1},
	};
	
//go in same row from spot to end
	wall_found = -1;
	while (go_col < end_col)
	{
		here = grid[ir][go_col];
		if (grid[ir][go_col] == WALL)
			wall_found = 1;
		go_col++;
	}
	if (wall_found < 0)
		return (FLS);
	
//go in same row from spot to 0, to beginning
	wall_found = -1;
	go_col = ic;
	while (go_col >= 0)
	{
		if (grid[ir][go_col] == WALL)
			wall_found = 1;
		go_col--;
	}
	if (wall_found < 0)
		return (FLS);
	
//go in same col DOWD
	wall_found = -1;
	while (go_row < end_row)
	{
		if (grid[go_row][ic] == WALL)
			wall_found = 1;
		go_row++;
	}
	if (wall_found < 0)
		return (FLS);
	
//go in same col UP
	go_row = ir;
	wall_found = -1;
	while (go_row >= 0)
	{
		if (grid[go_row][ic] == WALL)
			wall_found = 1;
		go_row--;
	}
	if (wall_found < 0)
		return (FLS);
	return TRU;
}


void	check(int number_row, int number_col)
{
	int ir = 0;
	int ic = 0;
	int wall_found;
	int current_point;
	
	int grid[8][9]=
	{
		{1,1,1,1,1,1,1,1,1},
		{3,3,3,1,1,1,0,0,0},
		{1,1,1,1,0,0,0,0,1},
		{1,1,0,0,0,0,1,1,1},
		{3,1,0,0,0,0,1,1},
		{1,1,0,0,0,'N',1,1,1},
		{1,0,0,0,1,1,1,1,1},
		{1,1,1,1,1,1,3,3,1},
	};
	
	wall_found = 0;
	current_point = -1;
	while (ir <= number_row)
	{
		ic = 0;
		while (ic < number_col)
		{
			//here i have specific piece of maze
			current_point = grid[ir][ic];
			if (current_point == FLOOR)
			{
				wall_found = is_there_a_wall(ir, ic, number_row, number_col);
				if (wall_found == 0)
					printf("error, row: %i, col: %i \n", ir, ic);
			}
			ic++;
		}
		ir++;
	}
}


void	fake_2d_array(void)
{
//	int valid_map[8][9]=
//	{
//		{1,1,1,1,1,1,1,1,1},
//		{3,3,3,1,1,1,0,0,0},
//		{1,1,1,1,0,0,0,0,1},
//		{1,1,0,0,0,0,1,1,1},
//		{3,1,0,0,0,0,1,1},
//		{1,1,0,0,0,'N',1,1,1},
//		{1,0,0,0,1,1,1,1,1},
//		{1,1,1,1,1,1,3,3,1},
//	};
//
	int number_row = 8; //how many strings I've read
	int number_col = 9; //how many in 1 row pieces

	check(number_row, number_col);
}
