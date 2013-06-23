/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	allocate_array.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "allocate_array.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	malloc_double
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */								
int** malloc_double(size_t* array_rows, size_t* array_cols){
	int** array_double;							/*The returning pointer.*/
	int i;										/*Loop control.*/
	
	/*	Checks if the allocation of memory for the array has been successful.	*/
	if( (array_double = (int** )malloc((*array_rows) * sizeof(int*))) == NULL){
		/*	Unsuccessful, set the sizes to zero and return an error value.	*/
		*array_rows = 0;
		*array_cols = 0;
		return 0;
	}
	
	for( i=0; i < *array_rows; i++){
		/*	Allocates an array for every element in the array.	*/
		if( (array_double[i] = (int*)malloc( (*array_cols)*sizeof(int))) == NULL){
			/*	Allocation has failed, free all allocated memory and return error value.*/
			/*	Goes through every element allocated and frees it.*/
			for(i--; i >= 0; i--){
				free( array_double[i]);
				array_double[i] = NULL;
			}
			/*	Sets rows and columns to zero to prevent segmentation faults.	*/
			*array_rows = 0;
			*array_cols = 0;
			free(array_double);
			array_double = NULL;
			return NULL;					/*Returns error value.	*/
		}
	}
	
	return array_double;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	malloc_double_char
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */							
char** malloc_double_char(size_t* array_rows, size_t* array_cols){
	char** array_double_char;					/*The returning pointer.*/
	int i;										/*Loop control.*/
	
	/*	Creates an array of pointers with size equal to the number of rows.	*/
	/*	Checks if the allocation of memory for the array has been successful.	*/
	if( (array_double_char = (char** )malloc((*array_rows) * sizeof(char*))) == NULL){
		/*	Unsuccessful, set the sizes to zero and return an error value.	*/
		*array_rows = 0;
		*array_cols = 0;
		return 0;
	}
	/*	Every pointer in the row is set to an array the size of the columns. */
	for( i=0; i < *array_rows; i++){
		/*	Allocates an array for every element in the array.	*/
		if( (array_double_char[i] = (char*) malloc( ( (*array_cols)*sizeof(char)))) == NULL){
			/*	Allocation has failed, free all allocated memory and return error value.*/
			/*	Goes through every element allocated and frees it.*/
			for(i--; i >= 0; i--){
				free( array_double_char[i]);
				array_double_char[i] = NULL;
			}
			/*	Sets rows and columns to zero to prevent segmentation faults.	*/
			*array_rows = 0;
			*array_cols = 0;
			free(array_double_char);
			array_double_char = NULL;
			return NULL;					/*Returns error value.*/
		}
	}
	
	return array_double_char;	
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	array_one_to_two
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */	
int** array_one_to_two(int* array_one, size_t* array_one_len, size_t* row_len, 
						size_t* col_len){
	int** array, i, col, row;
	/*Makes sure there will not be a out of bounds error*/
	if(((*row_len) * (*col_len)) < *array_one_len){
		return NULL;
	}
	if( (array = (int**) malloc( (*row_len)*sizeof(int*))) == NULL){
		/*	Sets rows and columns to zero to prevent segmentation faults.	*/
		*row_len = 0;
		*col_len = 0;
		return NULL;						/*Allocation unsuccessful, return error value.*/
	}
	for(i = 0; i < (*row_len); i++){
		/*	Allocates an array for every element in the array.	*/
		if( (array[i] = (int*)malloc( (*col_len)*sizeof(int))) == NULL){
			/*	Allocation has failed, free all allocated memory and return error value.*/
			/*	Goes through every element allocated and frees it.*/
			for(i--; i >= 0; i--){
				free( array[i]);
				array[i] = NULL;
			}
			free(array);
			/*	Sets rows and columns to zero to prevent segmentation faults.	*/
			*row_len = 0;
			*col_len = 0;
			array = NULL;
			return NULL;
		}
	}
	
	/*	Now places the contents of the single array into the allocated double array.	*/
	for(i = 0, row = 0, col=-1; i < (*array_one_len); i++){
		if((row = i%(*row_len))==0){
			col++;
		}
		array[row][col] = array_one[i];
	}
	
	return array;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	array_one_to_two_char
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */	
char** array_one_to_two_char(char* array_one, size_t* array_one_len, size_t* row_len,
							size_t* col_len){
	char** array;
	int	i, col, row;
	
	/*Makes sure there will not be a out of bounds error*/
	if(( (*row_len) * (*col_len)) < (*array_one_len)){
		/*	Sets rows and columns to zero to prevent segmentation faults.	*/
		*row_len = 0;
		*col_len = 0;
		return NULL;
	}
	array = (char**) malloc( (*row_len)*sizeof(char*));
	for(i = 0; i < (*row_len);i++){
		/*	Allocates an array for every element in the array.	*/
		if( (array[i] = (char*)malloc( (*col_len)*sizeof(char))) == NULL){
			/*	Allocation has failed, free all allocated memory and return error value.*/
			/*	Goes through every element allocated and frees it.*/
			for(i--; i >= 0; i--){
				free( array[i]);
				array[i] = NULL;
			}
			free(array);
			array = NULL;
			
			*row_len = 0;
			*col_len = 0;
			return NULL;
		}
	}
	
	/*	Now places the contents of the single array into the allocated double array.	*/
	for(i = 0, row = 0, col=-1; i < (*array_one_len); i++){
		if((row=i% (*row_len))==0){
			col++;
		}
		array[row][col] = array_one[i];
	}
	return array;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	free_double_array
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */										
extern void free_double_array(int** array_double, size_t* row_len, size_t* col_len){
	int i;									/*Loop control.*/
	
	for( i=0; i < (*row_len); i++){
		free( array_double[i]);
		array_double[i] = NULL;
	}
	
	free( array_double);
	array_double = NULL;
	
	*row_len = 0;
	*col_len = 0;
}
