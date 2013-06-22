#ProblemEleven.mak
CC = gcc
WARNINGS = -Wall

all: ProblemEleven.exe

ProblemEleven.exe: file_reader.o allocate_array.o ProblemEleven.o 
	$(CC) $(WARNINGS)  file_reader.o allocate_array.o ProblemEleven.o \
	-o ProblemEleven.exe
	
allocate_array.o: allocate_array.c allocate_array.h
	$(CC) -c allocate_array.c
	
ProblemEleven.o: ProblemEleven.c ProblemEleven.h
	$(CC) -c ProblemEleven.c
	
clean:
	rm -rf *o ProblemEleven.exe
