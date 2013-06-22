/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	ProblemEleven.h
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	A program that finds and displays the largest product of four 
 *				adjacent numbers in a 20x20 array, stored in a file "array_contents.txt".
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		November 30th 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#include "ProblemEleven.h"

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	largest_horizontal
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Finds the largest product of any four numbers adjacent to eachother in a 
 *				horizontal line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		grid,			A 2 dimensional array whos elements will be checked.
 *				grid_rows,		The size of the arrays first dimension.
 *				grid_cols,		The size of the arrays second dimension.
 *	@return:	largest,		The largest product of any four adjacent numbers found in
 *								a horizontal line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Every element (that is three away from right side) is checked. It is 
 *				multiplied by the three values to its right. The product is compared against
 *				largest, and if larger, largest is assigned the products value. Once all
 *				elements have been checked, the largest result is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int largest_horizontal(int** grid, size_t* grid_rows, size_t* grid_cols){
	int product, largest;
	int i, j;
	
	largest = 0;
	/*Every position, except those in the last 3 columns, is multiplied with the three adjacent values below it.*/
	for(i=0;i< (*grid_rows);i++){
		for(j=0; j < ( (*grid_cols)-3); j++){
			product = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
			/*If the product is larger, than largest is replaced.*/
			if(product > largest){
				largest = product;
			}
		}
	}
	
	return largest;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	largest_vertical
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Finds the largest product of any four numbers adjacent to eachother in a 
 *				vertical line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		grid,			A 2 dimensional array whos elements will be checked.
 *				grid_rows,		The size of the arrays first dimension.
 *				grid_cols,		The size of the arrays second dimension.
 *	@return:	largest,		The largest product of any four adjacent numbers found in
 *								a vertical line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Every element (that is three away from bottom) is checked. It is 
 *				multiplied by the three values below it. The product is compared against
 *				largest, and if larger, largest is assigned the products value. Once all
 *				elements have been checked, the largest result is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int largest_vertical(int** grid, size_t* grid_rows, size_t* grid_cols){
	int product, largest;
	int i, j;
	
	largest = 0;
	/*Every position, except the last 3 rows, is mulitplied together with the four adjacent numbers in the row*/
	for(i=0; i < ( (*grid_rows)-3);i++){
		for(j=0; j < (*grid_cols); j++){
			product = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j];
			/*If the product is larger, largest is replaced.*/
			if(product > largest){
				largest = product;
			}
		}
	}
	
	return largest;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	largest_left_diagonal
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Finds the largest product of any four numbers adjacent to eachother in a 
 *				diagonal line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		grid,			A 2 dimensional array whos elements will be checked.
 *				grid_rows,		The size of the arrays first dimension.
 *				grid_cols,		The size of the arrays second dimension.
 *	@return:	largest,		The largest product of any four adjacent numbers found in
 *								a diagonal line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Every element (that is three away from bottom and three away from the right
 *				side) is checked. It is multiplied by the three values in a diagonal line. 
 *				The product is compared against largest, and if larger, largest is assigned 
 *				the products value. Once all elements have been checked, the largest result 
 *				is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int largest_left_diagonal(int** grid, size_t* grid_rows, size_t* grid_cols){
	int product, largest;
	int i, j;
	
	largest = 0;
	/* Every position in the array, except the first three columns and rows, are checked and its contents
	 * multiplied with the next four numbers in a left diagonal path*/
	for(i=0; i < ( (*grid_rows)-3); i++){
		for(j=0; j < ( (*grid_cols)-3); j++){
			product = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
			/*If its product is larger, than the largest is replaced with it.*/
			if(product > largest){
				largest = product;
			}
		}
	}
	
	return largest;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	largest_right_diagonal
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Finds the largest product of any four numbers adjacent to eachother in a 
 *				right diagonal line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		grid,			A 2 dimensional array whos elements will be checked.
 *				grid_rows,		The size of the arrays first dimension.
 *				grid_cols,		The size of the arrays second dimension.
 *	@return:	largest,		The largest product of any four adjacent numbers found in
 *								a right diagonal line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Every element (that is three away from top and three away from the right
 *				side) is checked. It is multiplied by the three values in a 
 *				line. The product is compared against largest, and if larger, largest is  
 *				assigned the products value. Once all elements have been checked, the  
 *				largest result is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int largest_right_diagonal(int** grid, size_t* grid_rows, size_t* grid_cols){
	int product, largest;
	int i, j;
	
	largest = 0;
	/* Every position in the array, except the first three rows and the last 3 columns, are checked and its contents
	 * multiplied with the next four numbers in a right diagonal path*/
	for(i=3; i< (*grid_rows);i++){
		for( j=0; j < ( (*grid_cols)-3); j++){
			product = grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3];
			/*If its product is larger, than the largest is replaced with it.*/
			if(product > largest){
				largest = product;
			}
		}
	}
	
	return largest;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	largest_product
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Finds the largest product of any four numbers adjacent to eachother.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		grid,			A 2 dimensional array whos elements will be checked.
 *				grid_rows,		The size of the arrays first dimension.
 *				grid_cols,		The size of the arrays second dimension.
 *	@return:	largest,		The largest product of any four adjacent numbers found line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	The largest of any four elements in any direction, a vertical line,
 *				horizonal line, diagonal, or right diagonal line is found and compared
 *				against eachother. The largest one is returned.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int largest_product(int** grid, size_t* grid_rows, size_t* grid_cols){
	int largest, product;
	
	/* The double array is seached vertically, horizontally, and diagonally for the highest product of four numbers,
	 * the largest is replaced if the product is greater.*/
	largest = 0;
	if((product = largest_horizontal(grid, grid_rows, grid_cols)) > largest){
		largest = product;
	}
	if((product = largest_vertical(grid, grid_rows, grid_cols))>largest){
		largest = product;
	}
	if((product = largest_left_diagonal(grid,grid_rows,grid_cols))>largest){
		largest = product;
	}
	if((product = largest_right_diagonal(grid,grid_rows,grid_cols))>largest){
		largest = product;
	}
	
	return largest;
}

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	main
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	A program that finds the highest product of any four numbers in a grid.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		grid,			A 2 dimensional array whos elements will be checked.
 *				grid_rows,		The size of the arrays first dimension.
 *				grid_cols,		The size of the arrays second dimension.
 *	@return:	largest,		The largest product of any four adjacent numbers found line.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Algorithm:	Reads the numbers from the file into an array, converts the array into a
 *				20x20 double array. Then finds the highest product of any four adjacent
 *				numbers in the double array, and displays it to the screen. Waits five
 *				seconds before shutting down.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
int main( int argc, char** argv){	
	int largest;
	int countdown;
	
	int* buffer;
	size_t buff_len;
	
	int** grid;
	size_t grid_rows;
	size_t grid_cols;
	
	buff_len = 0;
	grid_rows = 20;
	grid_cols = 20;
	
	fprintf(stdout,"\nProgram will display the largest product of any four adjacent numbers"
					" stored in the file %s, then close after five seconds.",FILE_NAME);
	
	/*	Converts the contents in the file to an integer array.	*/
	if( (buffer = file_to_array(FILE_NAME, &buff_len)) == NULL){
		fprintf(stderr, "\nError occured while reading file.");
		return 1;
	}
	/*	Converts the single dimensional array into a double array.	*/
	if( (grid = array_one_to_two(buffer, &buff_len, &grid_rows, &grid_cols)) == NULL){
		fprintf( stderr, "\nError occured whilst converting to a two dimensional array.");
		return 2;
	}
	/*	Calculates and displays the highest product of four adjacent numbers in the grid.*/
	largest = largest_product(grid, &grid_rows, &grid_cols);
	
	fprintf(stdout, "\n\n\nThe largest product of four adjacent numbers in file %s is:\t%d",
			FILE_NAME,largest);
	
	/*	Counts down and closes the program.	*/
	fprintf(stdout,"\n\n\nProgram will close in ");
	for(countdown = 5; countdown > 0; countdown--){
		fprintf(stdout,"%d...",countdown);
		sleep(1);
	}
	return 0;
}
