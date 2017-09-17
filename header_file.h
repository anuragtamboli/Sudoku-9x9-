/* 
Date 15 September 2017
Auther Anurag Tamboli
anurag.tamboli@hotmail.com
*/

//************Global Parameter**************************//
typedef struct
{
	char value;
	char array[9];
	int flag;
}INPUT;

extern INPUT* matrix[9][9];
extern int event[];
//******************************************************//

//************Global Function Declaration***************//
void initialize(void); 							// Initialize matrix of 3X3 and structure write every value as 42.
void input_sudoku(void); 						// Takes input from user
void print_sudoku(void); 						// Prints sudoku
void print_probable_values_cube(void); 			// Prints probable values
void cube(int i, int j); 						// sort probable values in one 3x3 matrix
void cube_check(int i, int j); 					// Write value at the place of cell when only one probable value found
void row(int i); 								// sort probable values in row
void row_check( int i); 						// Write value at the place of cell when only one probable value found
void print_probable_values_row(int i); 			// Prints Probable values of rows
void column(int j); 							// Sort probable values in column
void column_check(int j); 						// Write values at the place of cell when only one probable values
void print_probable_values_column(int j); 		// Print probable values of rows
void initialize_probable_values(void); 			// Calculate probable values for every cube, row and column
int validate_sudoku(void); 						// It will check if entered values are valid or not
void search_cube(int i, int j); 				// Finding cell values in cube then registering event
void search_row(int i); 						// Finding cell values in row then registring event
void search_column(int j); 						// Finding column values in row then registring event
void print_probable_values(int i, int j);		// Print probable values at each place when i =11 or j= 11 and specific value
int exit_function(void); 						// Exit function for checking how many places have values.
void search_cell(void); 						// Searching for each cell.
//******************************************************//

