/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	ProblemEleven.h
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	To create a program that finds and displays the largest product of four 
 *				adjacent numbers in a 20x20 array, stored in a file "array_contents.txt".
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		November 30th 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#ifndef PROBLEMELEVEN_H
#define PROBLEMELEVEN_H 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

#include "allocate_array.h"
#include "file_reader.h"

/*sleep waits one second for every x*/
#define sleep(x) Sleep(1000*x)
/*name of the file where the contents of the array is stored.*/
#define FILE_NAME "array_contents.txt"

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
 */
extern int largest_horizontal(int** grid, size_t* grid_rows, size_t* grid_cols);

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
 */
extern int largest_vertical(int** grid, size_t* grid_rows, size_t* grid_cols);

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
 */
extern int largest_left_diagonal(int** grid, size_t* grid_rows, size_t* grid_cols);

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
 */
extern int largest_right_diagonal(int** grid, size_t* grid_rows, size_t* grid_cols);

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
 */
extern int largest_product(int** grid, size_t* grid_rows, size_t* grid_cols);

#endif
