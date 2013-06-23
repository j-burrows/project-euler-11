/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	file_reader.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Provide functions that read files and store the contents in an array.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 30th 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef FILE_TO_ARRAY_H
#define FILE_TO_ARRAY_H 1

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	required_buff_len
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Returns the required buffer space to store the entire file in text format.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		filename,		The location of the file to be read.
 |	@return:	buff_len,		The required buffer length to store the file. 
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Error:		If there is a error reading the file, the file is closed, and a length of
 |				zero is returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern size_t required_buff_len(char* filename);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	required_array_len
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Returns the length an array would have to be to store the number contents
 |				of the numbers in a given file.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		filename,		The location of the file to be read.
 |	@return:	array_len,		The required array length to store the numbers in a file. 
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Error:		If there is a error reading the file, the file is closed, and a length of
 |				zero is returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern size_t required_array_len(char* filename);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	required_array_len
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Returns the integer contents of a file in an array format.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		filename,		The location of the file to be read.
 |				array_len,		Length of the array, will be changed to match.
 |	@return:	array,			A pointer to the array of integers created from file.
 |				0,				The read was unsuccessful.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Errors:		If memory failed to allocate or there was an error reading the file, the
 |				size of the array is set to zero, and a value of zero is returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
extern int* file_to_array(char* filename, size_t* array_len);

#endif
