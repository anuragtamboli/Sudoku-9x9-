/* 
Date 18 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include"header_file.h"
void search_cube(int i, int j)
{
	int flag = 0, temp1 = i, temp2= j, flag1 = 0, k, z, dummy, lim1=i+3, lim2=j+3;
	for(z = 49 ; z<58; z++)
	{
		for(temp1=i; temp1<lim1; temp1++)
		{
			for(temp2=j; temp2<lim2; temp2++)
			{
				if(matrix[temp1][temp2]->value == z)
				{
					flag += 1;
				}
			}
		}
		dummy = z-49;
		if( flag == 0)
		{
			for(temp1=i; temp1<lim1; temp1++)
			{
				for(temp2=j; temp2<lim2; temp2++)
				{
					if(matrix[temp1][temp2]->array[dummy] == '*' && matrix[temp1][temp2]->flag == 0)
					{
						flag1 += 1;
					}
				}
			}
			if(flag1 == 1)
			{
				for(temp1 = i; temp1<lim1; temp1++)
				{
					for(temp2 = j; temp2<lim2; temp2++)
					{
						if(matrix[temp1][temp2]->array[dummy] == '*' && matrix[temp1][temp2]->flag == 0)
						{
							matrix[temp1][temp2]->value = dummy + 49;
							matrix[temp1][temp2]->flag = 1;
							event[0] = temp1+1;
							event[1] = temp2+1;											
							for(k = 0; k<9; k++)
							{
								matrix[temp1][temp2]->array[k] = '$';
							}
						}
					}
				}
			}
		}
		flag = 0;
		flag1 = 0;
	}
}

void search_row(int i)
{
	int flag = 0, temp1 = i, temp2, flag1 = 0, k, z, dummy;
	for(z = 49 ; z<57; z++)
	{
		for(temp2; temp2<9; temp2++)
		{
			if(matrix[temp1][temp2]->value == z)
			{
				flag += 1;
			}
		}
		dummy = z-49;
		if( flag == 0)
		{
			for(temp2=0; temp2<9; temp2++)
			{
				if(matrix[temp1][temp2]->array[dummy] == '*' && matrix[temp1][temp2]->flag == 0)
				{
					flag1 += 1;
				}
			}
			if(flag1 == 1)
			{
				for(temp2 = 0; temp2<9; temp2++)
				{
					if(matrix[temp1][temp2]->array[dummy] == '*' && matrix[temp1][temp2]->flag == 0)
					{
						matrix[temp1][temp2]->value = dummy + 49;
						matrix[temp1][temp2]->flag = 1;
						event[0] = temp1+1;
						event[1] = temp2+1;
						for(k = 0; k<9; k++)
						{
							matrix[temp1][temp2]->array[k] = '$';
						}
					}
				}
			}
		}
		flag = 0;
		flag1 = 0;
	}
}

void search_column(int j)
{
	int flag = 0, temp1, temp2 = j, flag1 = 0, k, z, dummy;
	for(z = 49 ; z<57; z++)
	{
		for(temp1=0; temp1<9; temp1++)
		{
			if(matrix[temp1][temp2]->value == z)
			{
				flag += 1;
			}
		}
		dummy = z-49;
		if( flag == 0)
		{
			for(temp1=0; temp1<9; temp1++)
			{
				if(matrix[temp1][temp2]->array[dummy] == '*' && matrix[temp1][temp2]->flag == 0)
				{
					flag1 += 1;
				}
			}
			if(flag1 == 1)
			{
				for(temp1 = 0; temp1<9; temp1++)
				{
					if(matrix[temp1][temp2]->array[dummy] == '*' && matrix[temp1][temp2]->flag == 0)
					{
						matrix[temp1][temp2]->value = dummy + 49;
						matrix[temp1][temp2]->flag = 1;
						event[0] = temp1+1;
						event[1] = temp2+1;
						for(k = 0; k<9; k++)
						{
							matrix[temp1][temp2]->array[k] = '$';
						}
					}
				}
			}
		}
		flag = 0;
		flag1 = 0;
	}
}
int exit_function(void)
{
	int i,j,flag=0;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(matrix[i][j]->flag == 1)
			{
				flag += 1;
			}
		}
	}
	return flag;
}
void search_cell(void)
{
	int i=0, j=0, k=0, flag, dummy = 0;
	for(i = 0; i< 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(matrix[i][j]->flag == 0)
			{
				for(k=0; k < 9; k++)
				{
					if(matrix[i][j]->array[k] == '*')
					{
						flag += 1;
						dummy = k+1;
					}
				}
				if(flag == 1)
				{
					matrix[i][j]->value = 48 + dummy;
					matrix[i][j]->flag = 1;
					event[0] = i+1;
					for(k = 0; k<9; k++)
					{
						matrix[i][j]->array[k] = '$';
					} 
				}
				else
				{
					flag = 0;
				}
			}
		}
	}
}
