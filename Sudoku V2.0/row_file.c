/* 
Date 18 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

#include<stdio.h>
#include"header_file.h"

void row(int i)
{
	int temp1, temp2, dummy;
	temp1 = i;
	for( temp2=0; temp2<9; temp2++)
	{
		if(matrix[temp1][temp2]->value == '*')
		{
			for( int i1 = 0; i1<9; i1++)
			{
				if(matrix[temp1][i1]->flag==1)
				{
					// Comparing cell value with probable values
					dummy = (int)matrix[temp1][i1]->value - '0';
					matrix[temp1][temp2]->array[(dummy-1)] = '$';
				}
			}
		}
	}
}

void row_check( int i)
{
	int temp1, temp2, check_flag = 0, k; 
	temp1 = i;
	for( temp2 = 0; temp2<9; temp2++)
	{
		if(matrix[temp1][temp2]->flag == 0)
		{
			check_flag += 1;
		}
	}
	if(check_flag == 1)
	{
		for( temp2 = 0; temp2<9; temp2++)
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

void print_probable_values_row(int i)
{
	int j=0, k=0;
	printf("\n");
	for(j=0;j<9;j++)
	{
		printf("[%d][%d] - ",(i+1),(j+1));
		for(k=0; k<9; k++)
		{
			printf("[%d]",matrix[i][j]->array[k]);
		}
		printf("\n");
	}
	printf("\n");
}
