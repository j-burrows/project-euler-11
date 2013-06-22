/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	allocate_array.h
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Provide allocation and deallocation methods for multi-dimensional arrays.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		December 13th, 2012.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#ifndef ALLOCATE_ARRAY_H 
#define ALLOCATE_ARRAY_H 1

#include <string.h>
#include <stdlib.h>

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	malloc_double
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Allocates memory for a double array.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		array_rows,		The desired rows in the array.
 *				array_cols,		The desired columns in the array
 *	@return:	array_double,	A pointer to the newly created double array.
 *				0,				The allocation was unsuccessful.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */							
extern int** malloc_double(size_t* array_rows, size_t* array_cols);


/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	malloc_double_char
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Allocates memory for a double array of characters.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		array_rows,		The desired rows in the array.
 *				array_cols,		The desired columns in the array
 *	@return:	array_double_char,	A pointer to the newly created double array of chars.
 *				NULL,			The allocation was unsuccessful.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */							
extern char** malloc_double_char(size_t* array_rows, size_t* array_cols);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	array_one_to_two
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Converts a single array into a double array of integers.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		array_one,		The array whos contents will be copied into double array.
 *				array_one_len,	The length of the given array.
 *				row_len,		The number of rows in the two dimensional array.
 *				col_len,		The number of columns in the two dimensional array.
 *	@return:	array_double_char,	A pointer to the newly created double array of chars.
 *				NULL,			The allocation was unsuccessful, or the sizes were bad.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */		
extern int** array_one_to_two(int* array_one, size_t* array_one_len, size_t* row_len, 
									size_t* col_len);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	array_one_to_two_char
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Converts a single array into a double array of chars.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		array_one,		The array whos contents will be copied into double array.
 *				array_one_len,	The length of the given array.
 *				row_len,		The number of rows in the two dimensional array.
 *				col_len,		The number of columns in the two dimensional array.
 *	@return:	array_double_char,	A pointer to the newly created double array of chars.
 *				NULL,			The allocation was unsuccessful, or the sizes were bad.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */		
extern char** array_one_to_two_char(char* array_one, size_t* array_one_len, size_t* row_len, 
									size_t* col_len);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Subroutine:	free_double_array
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Frees all elements in a double array of integers and sets sizes to zero.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		array_double,	The double array that will have all allocated memory freed.
 *				row_len,		The number of rows in the two dimensional array.
 *				col_len,		The number of columns in the two dimensional array.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */										
extern void free_double_array(int** array_double, size_t* row_len, size_t* col_len);

#endif
