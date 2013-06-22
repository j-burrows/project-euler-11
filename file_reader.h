/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Filename:	file_to_array.h
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Provide functions that read files and store the contents in an array.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Author:		Jonathan Burrows
 *	Date:		November 30th 2012
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
#ifndef FILE_TO_ARRAY_H
#define FILE_TO_ARRAY_H 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	required_buff_len
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Returns the required buffer space to store the entire file in text format.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		filename,		The location of the file to be read.
 *	@return:	buff_len,		The required buffer length to store the file. 
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
extern size_t required_buff_len(char* filename);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	required_array_len
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Returns the length an array would have to be to store the number contents
 *				of the numbers in a given file.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		filename,		The location of the file to be read.
 *	@return:	buff_len,		The required array length to store the numbers in a file. 
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
extern size_t required_array_len(char* filename);

/*
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Function:	required_array_len
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	Purpose:	Returns the integer contents of a file in an array format.
 === === === === === === === === === === === === === === === === === === === === === === ===
 *	@param:		filename,		The location of the file to be read.
 *				array_len,		Length of the array, will be changed to match.
 *	@return:	array,			A pointer to the array of integers created from file.
 === === === === === === === === === === === === === === === === === === === === === === ===
 */
extern int* file_to_array(char* filename, size_t* array_len);

#endif
