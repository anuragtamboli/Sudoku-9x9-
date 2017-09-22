/* 
Date 18 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

#include<stdio.h>
#include"header_file.h"

void cube(int i, int j) // Here how to give decide cubes think
{
	int i1, j1, dummy=0, temp1=i, temp2=j, lim1, lim2; // i1& j1 variables for running a loop which will find place value which are already filled
	lim1 = temp1+3;
	lim2 = temp2+3;
	for(temp1; temp1<lim1; temp1++)
	{
		for(temp2=j; temp2<lim2; temp2++)
		{
			if(matrix[temp1][temp2]->value == '*')
			{
				//Logic for probable values
				for(i1 = i; i1<lim1; i1++)
				{
					for(j1=j; j1<lim2; j1++)
					{
						if(matrix[i1][j1]->flag == 1)
						{
							// Comparing cell value with probable values
							dummy = (int)matrix[i1][j1]->value - '0';
							matrix[temp1][temp2]->array[(dummy-1)] = '$';
						}
					}
				}
			}
		}
	}
}

void print_probable_values_cube(void)
{
	int i=0, j=0, k=0;
	printf("\n");
	for(i=0;i<9;i++)
	{
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
}

void cube_check(int i, int j)
{
	int temp1, temp2, lim1, lim2, k;
	temp1 = i;
	temp2 = j;
	lim1 = temp1+3;
	lim2 = temp2+3;
	int check_flag = 0;
	for(temp1; temp1<lim1; temp1++)
	{
		for(temp2=j; temp2<lim2; temp2++)
		{
			if(matrix[temp1][temp2]->flag == 0)
			{
				check_flag += 1;
			}
		}
	}
	if(check_flag == 1)
	{
		temp1 = i; // Initialization for temp1, temp2
		temp2 = j;
		for(temp1; temp1<lim1; temp1++)
		{
			for(temp2=j; temp2<lim2; temp2++)
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
}

