/* 
Date 15 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include"header_file.h"


void initialize(void)
{
	int i=0, j=0, k = 0;
	// Initialization for each cell
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			matrix[i][j] = (INPUT *) malloc(sizeof(INPUT));
			matrix[i][j]->value = '*';
			for( k = 0; k<9; k++)
			{
				matrix[i][j]->array[k] = '*';
			}
			matrix[i][j]->flag = 0;
		}
	}
}
void input_sudoku(void)
{
	int i=0, j=0, k=0;
	FILE *fp;
   	char dummy;
	printf("\n taking input from file ""/home/anurag/Desktop/Sudoku/input3.txt"" ");
	fp = fopen("/home/anurag/Desktop/Sudoku/Sudoku.V0.17/SudokuV0.17/input.txt", "r");
	printf("\n Inside function sudoku");
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			matrix[i][j]->value = fgetc((FILE*)fp);
			if(matrix[i][j]->value == ' ' || matrix[i][j]->value == '\n' )
			{
				matrix[i][j]->value = fgetc((FILE*)fp);
				if(matrix[i][j]->value == '*')
				{
					matrix[i][j]->flag = 0;
				}
				else
				{
					matrix[i][j]->flag = 1;
				}
			}
			else
			{
				if(matrix[i][j]->value == '*')
				{
					matrix[i][j]->flag = 0;
				}
				else
				{
					matrix[i][j]->flag = 1;
				}
			}
		}
		printf("\n");
	}
}
void print_sudoku(void)
{
	int i=0, j=0;
	printf("\n");
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			printf("[%c]{%d} ",matrix[i][j]->value,matrix[i][j]->flag);
		}
		printf("\n");
	}
}
void initialize_probable_values(void)
{
	int i=0,j=0;
	//Initializing probable values in Cube
	for(i=0;i<9;i=i+3)
	{
		for(j=0;j<9;j=j+3)
		{
			cube(i,j);
		}
	}
	//Initializing probable values in rows
	for(i=0;i<9;i++)
	{
		row(i);
	}
	//Initializing probable values in column
	for(i=0;i<9;i++)
	{
		column(i);
	}
}
int validate_sudoku(void)
{
	int i, j, k, flag=0, valid = 0;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			for(k = 0; k<9; k++)
			{
				if(matrix[i][j]->array[k] == '$')
				{
					flag +=1;
				}
			}
			if(flag == 9)
			{
				valid = 1;
			}
			flag = 0;
		}
	}
	return valid;
}
void print_probable_values(int i, int j)
{
	int i1=0, j1=0, k=0;
	if(i==11 && j==11)
	{
		for(i1; i1<9;i1++)
		{
			for(j1=0;j1<9;j1++)
			{
				printf("\n[%d][%d] - [%c]{%d} -> ",(i1+1),(j1+1), matrix[i1][j1]->value, matrix[i1][j1]->flag);
				for(k=0; k<9; k++)
				{
					printf("[%d]",matrix[i1][j1]->array[k]);
				}
			}
			printf("\n");
		}
	}
	else
	{
		printf("\n[%d][%d] - ",i,j);
		for(k=0; k<9; k++)
		{
			printf("[%d]",matrix[i1][j1]->array[k]);
		}
	}
}
