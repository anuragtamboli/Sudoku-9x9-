/*  
Date 20 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include"header_file.h"
#include<malloc.h>

INPUT_NEW* matrix_new[9][9];
char event_advance[2];

NODE *head = NULL;

void advance(void)
{
	int i=0, j=0, k=0, valid_flag;
	initialize_new();			// Initialize_new will initiaize matrix_new[][]
	create_copy();				// Create_copy() will create one more copy of matrix[][]
	fill_place();				// This function basically guess value at each cell and then fill all places accordingly then check for validity (chain reaction)
}

void initialize_new(void)
{
	int i=0, j=0, k = 0;
	// Initialization for each cell
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			matrix_new[i][j] = (INPUT_NEW *) malloc(sizeof(INPUT));
			matrix_new[i][j]->value = '*';
			for( k = 0; k<9; k++)
			{
				matrix_new[i][j]->array[k] = '*';
			}
			matrix_new[i][j]->flag = 0;
			matrix_new[i][j]->flag1 = 0;
		}
	}
}
void create_copy(void)
{
	int i=0, j=0, k=0;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			matrix_new[i][j]->value = matrix[i][j]->value;
			matrix_new[i][j]->flag = matrix[i][j]->flag;
			matrix_new[i][j]->flag1 = 0;
			for(k=0 ; k<9 ; k++)
			{
				matrix_new[i][j]->array[k] = matrix[i][j]->array[k];
			}
		}
	}
}
void fill_place(void)    
{
	int i=0, j=0, k=0, l=0, exit_flag=0, valid_flag=0, dummy=0, iteration = 0, dummy1, test_condition1 = 0;
	for(i=0 ; i<9 ; i++)
	{
		for(j=0; j<9 ; j++)
		{
			if(matrix_new[i][j]->flag == 0)// Looking for a cell not filled with any number
			{
				for(k=0 ; k<9 ; k++)
				{
					if(matrix_new[i][j]->array[k] == '*') // Looking for frist value to fill in matrix_new
					{
						matrix_new[i][j]->value = 49 + k;
						matrix_new[i][j]->flag1 = 1;
						// Repeat till you find a mistake
						for(l=0 ; l<9 ; l++)				//  Writing $ at any other places for no confusion
						{
							matrix_new[i][j]->array[l] = '$';
						}
						initialize_probable_values_advance();	
						valid_flag = validate_sudaku_advance();
						if(valid_flag == 0)					// After filling first place it will check validity
						{
							exit_flag = 0;
							while(exit_flag == 0)			// Same paper & pen algorithm
							{
								dummy1 += 1;
								for(int i1=0; i1<9; i1 = i1+3)
								{
									for(int j1=0; j1<9; j1 = j1+3)
									{
										search_cube_advance(i1,j1);
										if(event_advance[0]!= 0 && event_advance[1] != 0)
										{
											initialize_probable_values_advance();
											event[0] = 0; 
											event[1] = 0;
										}
									}
								}
								valid_flag = validate_sudaku_advance();
								if(valid_flag == 1)
								{
									exit_flag = 1;
									something(i, j, k);
									break;
								}
								for(int i1=0; i1<9; i1++)
								{
									search_row_advance(i1);
									if(event_advance[0]!= 0 && event_advance[1] != 0)
									{
										initialize_probable_values_advance();
										event_advance[0] = 0; 
										event_advance[1] = 0;
									}
								}
								valid_flag = validate_sudaku_advance();
								if(valid_flag == 1)
								{
									exit_flag = 1;
									something(i, j, k);
									break;
								}
								for( int j1=0; j1<9; j1++)
								{
									search_column_advance(j1);
									if(event_advance[0]!= 0 && event_advance[1] != 0)
									{
										initialize_probable_values_advance();
										event_advance[0] = 0; 
										event_advance[1] = 0;
									}
								}
								valid_flag = validate_sudaku_advance();
								if(valid_flag == 1)
								{
									exit_flag = 1;
									something(i, j, k);
									break;
								}
								search_cell_advance();
								if(event_advance[0]!= 0 && event_advance[1] != 0)
								{
									initialize_probable_values_advance();
									event_advance[0] = 0; 
									event_advance[1] = 0;
								}
								valid_flag = validate_sudaku_advance();
								if(valid_flag == 1)
								{
									exit_flag = 1;
									something(i, j, k);
									break;
								}
								exit_flag = exit_function_advance();
								test_condition1 = exit_flag;
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
							if(valid_flag == 0 && test_condition1 == 81) // write back to matrix[][] only if valid value filled the place and every position is filled.
							{
								i=10; j=10; k=10; 
								for(int ii=0; ii<9; ii++)    			// Writing back value to matrix[][] variable
								{
									for(int jj=0; jj<9 ; jj++)
									{
										if(matrix_new[ii][jj]->flag1 == 1)
										{
											matrix[ii][jj]->value = matrix_new[ii][jj]->value;
											matrix[ii][jj]->flag = 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	valid_flag = validate_sudaku_advance();
	printf("\n valid_flag = %d\n", valid_flag);
}
void initialize_probable_values_advance(void)
{
	int i=0,j=0;
	//Initializing probable values in Cube
	for(i=0;i<9;i=i+3)
	{
		for(j=0;j<9;j=j+3)
		{
			cube_advance(i,j);
		}
	}
	//Initializing probable values in rows
	for(i=0;i<9;i++)
	{
		row_advance(i);
	}
	//Initializing probable values in column
	for(i=0;i<9;i++)
	{
		column_advance(i);
	}
}
void cube_advance(int i, int j) // Here how to give decide cubes think
{
	int i1, j1, dummy=0, temp1=i, temp2=j, lim1, lim2; // i1& j1 variables for running a loop which will find place value which are already filled
	lim1 = temp1+3;
	lim2 = temp2+3;
	for(temp1; temp1<lim1; temp1++)
	{
		for(temp2=j; temp2<lim2; temp2++)
		{
			if(matrix_new[temp1][temp2]->value == '*')
			{
				//Logic for probable values
				for(i1 = i; i1<lim1; i1++)
				{
					for(j1=j; j1<lim2; j1++)
					{
						if(matrix_new[i1][j1]->flag1 == 1 || matrix_new[i1][j1]->flag == 1)
						{
							// Comparing cell value with probable values
							dummy = matrix_new[i1][j1]->value - '0';
							matrix_new[temp1][temp2]->array[(dummy-1)] = '$';
						}
						dummy = 0;
					}
				}
			}
		}
	}
}
void row_advance(int i)
{
	int temp1, temp2, dummy=0;
	temp1 = i;
	for( temp2=0; temp2<9; temp2++)
	{
		if(matrix_new[temp1][temp2]->value == '*')
		{
			for( int i1 = 0; i1<9; i1++)
			{
				if(matrix_new[temp1][i1]->flag1==1 || matrix_new[temp1][i1]->flag == 1)
				{
					// Comparing cell value with probable values
					dummy = matrix_new[temp1][i1]->value - '0';
					matrix_new[temp1][temp2]->array[(dummy-1)] = '$';
				}
				dummy = 0;
			}
		}
	}
}
void column_advance(int j)
{
	int temp1, temp2, dummy=0;
	temp2 = j;
	for( temp1=0; temp1<9; temp1++)
	{
		if(matrix_new[temp1][temp2]->value == '*')
		{
			for( int j1 = 0; j1<9; j1++)
			{
				if(matrix_new[j1][temp2]->flag1==1 || matrix_new[j1][temp2]->flag == 1)
				{
					// Comparing cell value with probable values
					dummy = matrix_new[j1][temp2]->value - '0';
					matrix_new[temp1][temp2]->array[(dummy-1)] = '$';
				}
				dummy = 0;
			}
		}
	}
}
int validate_sudaku_advance(void)
{
	int i=0, j=0, k=0, flag=0, valid=0;
	for(i=0 ; i<9 ; i++)
	{
		for(j=0 ; j<9 ; j++)
		{
			if(matrix_new[i][j]->flag1 == 0 && matrix_new[i][j]->flag == 0)
			{
				for(k=0 ; k<9 ; k++)
				{
					if(matrix_new[i][j]->array[k] == '$')
					{
						flag += 1;
					}
				}
				if(flag == 9)
				{
					valid = 1; // Condition for not being valid
					return valid;
				}
				else
				{
					valid = 0; //Condition for being valid
				}
			}
			flag = 0;
		}
	}
	return valid;
}
void search_cube_advance(int i, int j)
{
	int flag = 0, temp1 = i, temp2= j, flag1 = 0, k, z, dummy, lim1=i+3, lim2=j+3;
	for(z = 49 ; z<58; z++)
	{
		for(temp1=i; temp1<lim1; temp1++)
		{
			for(temp2=j; temp2<lim2; temp2++)
			{
				if(matrix_new[temp1][temp2]->value == z)
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
					if(matrix_new[temp1][temp2]->array[dummy] == '*' && matrix_new[temp1][temp2]->flag == 0 && matrix_new[temp1][temp2]->flag1 == 0)
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
						if(matrix_new[temp1][temp2]->array[dummy] == '*' && matrix_new[temp1][temp2]->flag == 0 && matrix_new[i][j]->flag1 == 0 )
						{
							matrix_new[temp1][temp2]->value = dummy + 49;
							matrix_new[temp1][temp2]->flag1 = 1;
							event_advance[0] = temp1+1;
							event_advance[1] = temp2+1;	
							for(k = 0; k<9; k++)
							{
								matrix_new[temp1][temp2]->array[k] = '$';
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
void search_row_advance(int i)
{
	int flag = 0, temp1 = i, temp2, flag1 = 0, k, z, dummy;
	for(z = 49 ; z<57; z++)
	{
		for(temp2; temp2<9; temp2++)
		{
			if(matrix_new[temp1][temp2]->value == z)
			{
				flag += 1;
			}
		}
		dummy = z-49;
		if( flag == 0)
		{
			for(temp2=0; temp2<9; temp2++)
			{
				if(matrix_new[temp1][temp2]->array[dummy] == '*' && matrix_new[temp1][temp2]->flag == 0 && matrix_new[temp1][temp2]->flag1 == 0)
				{
					flag1 += 1;
				}
			}
			if(flag1 == 1)
			{
				for(temp2 = 0; temp2<9; temp2++)
				{
					if(matrix_new[temp1][temp2]->array[dummy] == '*' && matrix_new[temp1][temp2]->flag == 0 && matrix_new[temp1][temp2]->flag1 == 0)
					{
						matrix_new[temp1][temp2]->value = dummy + 49;
						matrix_new[temp1][temp2]->flag1 = 1;
						event_advance[0] = temp1+1;
						event_advance[1] = temp2+1;
						for(k = 0; k<9; k++)
						{
							matrix_new[temp1][temp2]->array[k] = '$';
						}
					}
				}
			}
		}
		flag = 0;
		flag1 = 0;
	}
}
void search_column_advance(int j)
{
	int flag = 0, temp1, temp2 = j, flag1 = 0, k, z, dummy;
	for(z = 49 ; z<57; z++)
	{
		for(temp1=0; temp1<9; temp1++)
		{
			if(matrix_new[temp1][temp2]->value == z)
			{
				flag += 1;
			}
		}
		dummy = z-49;
		if( flag == 0)
		{
			for(temp1=0; temp1<9; temp1++)
			{
				if(matrix_new[temp1][temp2]->array[dummy] == '*' && matrix_new[temp1][temp2]->flag == 0 && matrix_new[temp1][temp2]->flag1 == 0)
				{
					flag1 += 1;
				}
			}
			if(flag1 == 1)
			{
				for(temp1 = 0; temp1<9; temp1++)
				{
					if(matrix_new[temp1][temp2]->array[dummy] == '*' && matrix_new[temp1][temp2]->flag == 0 && matrix_new[temp1][temp2]->flag1 == 0)
					{
						matrix_new[temp1][temp2]->value = dummy + 49;
						matrix_new[temp1][temp2]->flag1 = 1;
						event_advance[0] = temp1+1;
						event_advance[1] = temp2+1;
						for(k = 0; k<9; k++)
						{
							matrix_new[temp1][temp2]->array[k] = '$';
						}
					}
				}
			}
		}
		flag = 0;
		flag1 = 0;
	}
}
void search_cell_advance(void)
{
	int i=0, j=0, k=0, flag, dummy = 0;
	for(i = 0; i< 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(matrix_new[i][j]->flag == 0 && matrix_new[i][j]->flag1 == 0)
			{
				for(k=0; k < 9; k++)
				{
					if(matrix_new[i][j]->array[k] == '*')
					{
						flag += 1;
						dummy = k+1;
					}
				}
				if(flag == 1)
				{
					matrix_new[i][j]->value = 48 + dummy;
					matrix_new[i][j]->flag1 = 1;
					event_advance[0] = i+1;
					event_advance[1] = j+1;
					for(k = 0; k<9; k++)
					{
						matrix_new[i][j]->array[k] = '$';
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
int exit_function_advance(void)
{
	int i,j,flag=0;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(matrix_new[i][j]->flag == 1 || matrix_new[i][j]->flag1 == 1)
			{
				flag += 1;
			}
		}
	}
	printf("\n Number of placed filled = %d", flag);
	if(flag == 81)
	{
		free_something();
	}
	return flag;
}
void print_sudaku_advance(void)
{
	int i=0, j=0;
	//printf("\n");
	for (i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			//printf("[%c]{%d}{%d} ",matrix_new[i][j]->value,matrix_new[i][j]->flag,matrix_new[i][j]->flag1);
		}
		//printf("\n");
	}
}
void print_probable_values_advance(int i, int j)
{
	int i1=0, j1=0, k=0, flag=0;
	if(i==11 && j==11)
	{
		for(i1; i1<9;i1++)
		{
			for(j1=0;j1<9;j1++)
			{
				//printf("\n[%d][%d] - [%c]{%d}{%d} -> ",(i1+1),(j1+1), matrix_new[i1][j1]->value, matrix_new[i1][j1]->flag, matrix_new[i1][j1]->flag1);
				for(k=0; k<9; k++)
				{
					//printf("[%d]",matrix_new[i1][j1]->array[k]);
					if(matrix_new[i1][j1]->array[k] == '$')
					{
						flag += 1;
					}
				}
				if(flag == 9)
				{
					//printf(" <--- ");
				}
				flag = 0;
			}
			//printf("\n");
		}
	}
	else
	{
		//printf("\n[%d][%d] - ",i+1,j+1);
		for(k=0; k<9; k++)
		{
			//printf("[%d]",matrix_new[i][j]->array[k]);
		}
	}
}
void print_probable_values_cube_advance(int i, int j)
{
	int i1=i, j1=j, k=0, lim1 = i+3, lim2 = j + 3;
	//printf("\n");
	for(i1;i1<lim1;i1++)
	{
		for(j1=j;j1<lim2;j1++)
		{
			if(matrix_new[i1][j1]->flag == 0 && matrix_new[i1][j1]->flag1 == 0)
			{	
				//printf("\n[%d][%d] - ",(i1+1),(j1+1));
				for(k=0; k<9; k++)
				{
					//printf("[%d]",matrix_new[i1][j1]->array[k]);
				}
				//printf("\n");
			}
		}
		//printf("\n");
	}
}
void print_probable_values_column_advance(int j)
{
	int i=0, k=0;
	printf("\n");
	for(i=0;i<9;i++)
	{
		if(matrix_new[i][j]->flag == 0 && matrix_new[i][j]->flag1 == 0)
		{	
			//printf("\n[%d][%d] - ",(i+1),(j+1));
			for(k=0; k<9; k++)
			{
				//printf("[%d]",matrix_new[i][j]->array[k]);
			}
			//printf("\n");
		}
	}
	//printf("\n");
}
void print_probable_values_row_advance(int i)
{
	int j=0, k=0;
	for(j=0;j<9;j++)
	{
		if(matrix_new[i][j]->flag == 0 && matrix_new[i][j]->flag1 == 0)
		{			
			//printf("\n[%d][%d] - ",(i+1),(j+1));
			for(k=0; k<9; k++)
			{
				//printf("[%d]",matrix_new[i][j]->array[k]);
			}
			//printf("\n");
		}
	}
	//printf("\n");
}
void something(int i1, int j1, int k1)
{
	NODE *temp = 0, *temp1 = 0;
	int ii=0, jj=0, kk=0;
	static int flag = 0;
	printf("\n flag = %d", flag);
	if(flag == 0)
	{
		head = (NODE *)malloc(sizeof(NODE));
		if(head == NULL)
		{
			perror("Error:");
			exit(0);
		}
		else
		{
			head->i = i1+1;
			head->j = j1+1;
			head->value = k1;
			head->next = NULL;
		}
		flag++;
	}
	else
	{
		temp = head;
		NODE *new_node = (NODE *)malloc(sizeof(NODE));
		printf("\n head = %x", head);
		if(new_node == NULL)
		{
			perror("");
			exit(0);
		}
		else
		{
			new_node->i = i1;
			new_node->j = j1;
			new_node->value = k1;
			new_node->next = NULL;
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}
	create_copy();
	temp1 = head;
	if(temp1->next == NULL)
	{
		ii = temp1->i;
		jj = temp1->j;
		kk = temp1->value;
		matrix_new[ii][jj]->array[kk] = '$';
	}
	else
	{
		while(temp1->next != NULL)
		{
			ii = temp1->i;
			jj = temp1->j;
			kk = temp1->value;
			matrix_new[ii][jj]->array[kk] = '$';
			temp1 = temp1->next;
			if(temp1->next == NULL)
			{
				ii = temp1->i;
				jj = temp1->j;
				kk = temp1->value;
				matrix_new[ii][jj]->array[kk] = '$';
			}
		}
	}
}
void free_something(void)
{
	NODE *temp;
	if(head == NULL)
	{
		//printf("\n No values in linked list");
	}
	else if(head->next == NULL)
	{
		free(head);
	}
	else
	{
		while(head->next != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
			if(head->next == NULL);
			{
				free(head);
			}
		}
	}
}
