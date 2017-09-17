/* 
Date 15 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

#include<stdio.h>
#include"header_file.h"

void column(int j)
{
	int temp1, temp2, dummy;
	temp2 = j;
	for( temp1=0; temp1<9; temp1++)
	{
		if(matrix[temp1][temp2]->value == '*')
		{
			for( int j1 = 0; j1<9; j1++)
			{
				if(matrix[j1][temp2]->flag==1)
				{
					dummy = (int)matrix[j1][temp2]->value - '0';
					matrix[temp1][temp2]->array[(dummy-1)] = '$';
				}
			}
		}
	}
}

void column_check(int j)
{
	int temp1, temp2, check_flag = 0, k; 
	temp2 = j;
	for( temp1 = 0; temp1<9; temp1++)
	{
		if(matrix[temp1][temp2]->flag == 0)
		{
			check_flag += 1;
		}
	}
	if(check_flag == 1)
	{
		for( temp1 = 0; temp1<9; temp1++)
		{
			if(matrix[temp1][temp2]->flag == 0)
			{
				for(k=0;k<9;k++)
				{
					if(matrix[temp1][temp2]->array[k]=='*')
					{
						matrix[temp1][temp2]->value = k+1;
						matrix[temp1][temp2]->flag = 1;
						event[0] = temp1;
						event[1] = temp2;
					}
				}
			}
		}
	}
}

void print_probable_values_column(int j)
{
	int i=0, k=0;
	for(i=0;i<9;i++)
	{
		printf("[%d][%d] - ",(i+1),(j+1));
		for(k=0; k<9; k++)
		{
			//printf("[%d]",matrix[i][j]->array[k]);
		}
		//printf("\n");
	}
	//printf("\n");
}
