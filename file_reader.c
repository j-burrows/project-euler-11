/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 *	Filename:	file_reader.c
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "file_reader.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	required_buff_len
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
size_t required_buff_len(char* filename){
	size_t buff_len = 0;					/*Return value.*/
	/*	For the reading of the file.	*/
	FILE* contents;
	char current;
	
	contents = fopen(filename, "r");
	/*	A character is continously read until end of file is reached.*/
	while( (current = fgetc(contents)) != EOF){
		/*	After every itteration buffer length is incrimented, if a valid character.	*/
		if( current == '\n'){
			current = ' ';
		}
		if( current == ' ' || ( current <= '9' && current >= '0')){
			buff_len++;
		}
	}
	
	/*	Checks if error has occured.	*/
	if(ferror(contents)){
		/*	Error has occured while reading, begin exit.	*/
		fclose(contents);					/*Closes file.*/
		return 0;							/*Returns error value.*/
	}
	fclose(contents);
	
	return buff_len;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	required_array_len
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
size_t required_array_len(char* filename){
	size_t array_len = 0;					/*Return value.*/
	/*	For the reading of the file.	*/
	FILE* contents;
	int number_start = 1;
	char current;
	
	contents = fopen(filename, "r");
	/*	Continous to read characters until the end of the file is reached.	*/
	while( (current = fgetc(contents)) != EOF){
		/*Checks to see if this character is the start of a new number.	*/
		if(current <= '9' && current >= '0'){
			/*Since the value is a number, it is possibly the start of a new number.*/
			if(number_start){
				/*Start of a new number, incriments required array length.*/
				number_start = 0;
				array_len++;
			}
		}
		else if(current == ' ' || current == '\n'){
			/*Since the character is a space, next number value is start of a new number.*/
			number_start = 1;
		}
	}
	
	/*	Checks if error has occured.	*/
	if(ferror(contents)){
		/*	Error has occured while reading.	*/
		fclose(contents);					/*Closes file.*/
		return 0;							/*Returns error value.*/
	}
	fclose(contents);
	
	return array_len;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	file_to_array
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
int* file_to_array(char* filename, size_t* array_len){
	int* array;								/*Return value*/
	/*	For reading data in from file.	*/
	FILE* contents;
	char* buffer;
	size_t buffer_len;
	char current, *deliminator;
	/*	Loop control.	*/
	int i;
	
	/*	Updates the lengths of the arrays to required lengths.*/
	buffer_len = required_buff_len(filename); 
	*array_len = required_array_len(filename);
	
	/*	Checks to make sure lengths are valid.	*/
	if(buffer_len == 0 || *array_len == 0){
		/*	Either error reading has occured, or invalid length exists. Set size to zero
		 *	and return error.	*/
		*array_len = 0;
		return 0;
	}
	
	/*	Allocates memory for arrays, checks if successful.	*/
	if( (buffer = malloc( (buffer_len + 1)*sizeof(char))) == NULL){
		/*	Allocation was unsuccessful.	*/
		*array_len = 0;						/*Size is reduced to zero.*/
		return 0;							/*Error value is returned.*/
	}
	if( (array = malloc( (*array_len)*sizeof(int))) == NULL){
		/*	Allocation was unsuccessful.	*/
		*array_len = 0;						/*Size is reduced to zero.*/
		return 0;							/*Error value is returned.*/
	}
	
	contents = fopen(filename, "r");
	/*	Goes through the file, adding every valid character to the buffer.	*/
	i = 0;
	while( i < buffer_len){
		/*Gets next character, checks if valid, and adds to buffer if so.*/
		current = fgetc(contents);
		
		/*	Converts any newlines to spaces before adding to buffer.	*/
		if( current == '\n'){
			current = ' ';
		}
		if( current == ' ' || ( current <= '9' && current >= '0')){
			buffer[i] = current;
			i++;
		}
	}
	buffer[i] = '\0';						/*Ends with null terminator.*/
	
	/*	Makes sure no errors occured while reading the file.	*/
	if(ferror(contents)){
		/*	An error has occured*/
		free(array);						/*Makes array unusable.*/
		array = NULL;
		free(buffer);						/*Frees the buffer.*/
		buffer = NULL;
		*array_len = 0;						/*Array size set to nothing.*/
		fclose(contents);
		return 0;							/*Error value is returned.*/
	}
	fclose(contents);						/*No errors, close and proceed.*/
	
	/*	Breaks the buffer down into its numbered components by seperating by spaces.	*/
	deliminator = strtok(buffer, " ");
	/*	Continous delminating values until the array is filled.	*/
	for(i = 0; i < (*array_len); i++){
		array[i] = atoi(deliminator);		/*The segment is converted into an integer.*/
		deliminator = strtok(NULL, " ");	/*Next value is polled.*/
	}
	free(buffer);
	return array;
}
