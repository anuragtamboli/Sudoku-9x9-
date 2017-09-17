/* 
Date 17 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

//ToDo List
//7). Write Make files with all flags and everything
//5). Advance
//9). Check routine for entering values using keyboard 
//*****************************************************//
//Cube logic and 9X9 Matrix
//*****************************************************//

#include<stdio.h>
#include<stdlib.h>
#include"header_file.h"

//*****************************************************//


INPUT* matrix[9][9];
int event[2]={0};

int main()
{
	int valid_flag = 0, exit_flag=0, i=0, j=0, dummy=0, iteration = 0, dummy1 = 0;
	initialize();
	input_sudoku();
	initialize_probable_values();
	valid_flag = validate_sudoku();
	if(valid_flag == 1)
	{
		printf("\n Entered sudoku values are not valid");
	}
	else
	{
		printf("\n Entered sudoku values are valid");
	}
	while(exit_flag == 0)
	{
		dummy1 += 1;
		iteration += 1;
		for(i=0; i<9; i = i+3)
		{
			for(j=0; j<9; j = j+3)
			{
				search_cube(i,j);
				if(event[0]!= 0 && event[1] != 0)
				{
					initialize_probable_values();
					event[0] = 0; 
					event[1] = 0;
				}
			}
		}
		for(i=0; i<9; i++)
		{
			search_row(i);
			if(event[0]!= 0 && event[1] != 0)
			{
				initialize_probable_values();
				event[0] = 0; 
				event[1] = 0;
			}
		}
		for(j=0; j<9; j++)
		{
			search_column(j);
			if(event[0]!= 0 && event[1] != 0)
			{
				initialize_probable_values();
				event[0] = 0; 
				event[1] = 0;
			}
		}
		search_cell();
		if(event[0]!= 0 && event[1] != 0)
		{
			initialize_probable_values();
			event[0] = 0; 
			event[1] = 0;
		}
		initialize_probable_values();
		exit_flag = exit_function();
		if(iteration == 1)
		{
			dummy = exit_flag;
		}
		else
		{
			if(dummy == exit_flag)
			{
				exit_flag = 1;
				break;
			}
			else
			{
				dummy = exit_flag;
			}
		}
		if(exit_flag == 81)
		{
			exit_flag = 1;
		}
		else
		{
			exit_flag = 0;
		}
	}
	print_sudoku();
	return 0;
}
