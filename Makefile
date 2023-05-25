# Initializing a variable with the flags
C_FLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Reference to the executable file
all : hsh

# Produice a executable with all the .o files
hsh : *.o
	gcc C_FLAGS *.o -o hsh

# Produice a .o with the main function
main.o : shell_main.c
	gcc C_FLAGS -c shell_main.c -o main.o

# Produice a .o file with all the string based functions
get_strlen.o : _get_strlen.c
	gcc C_FLAGS -c _get_strlen.c -o get_strlen.o
strcat.o : _strcat.c
	gcc C_FLAGS -c _strcat.c -o strcat.o
strcmp.o : _strcmp.c
	gcc C_FLAGS -c _strcmp.c -o strcmp.o
strcpy.o : _strcpy.c
	gcc C_FLAGS -c _strcpy.c -o strcpy.o
strdup.o : _strdup.c
	gcc C_FLAGS -c _strdup.c -o strdup.o
rev_string.o : _rev_string.c
	gcc C_FLAGS -c _rev_string.c -o rev_string.o

# Produice a .o file with source files containing digitial based functions
digit.o : digit_funcs.c
	gcc C_FLAGS -c digit_funcs.c -o digit.o

#  Produice a .o file with memory management files
realloc.o : _realloc.c
	gcc C_FLAGS -c _realloc.c -o mem.o
calloc.o : _calloc.c
	gcc C_FLAGS -c _calloc.c -o mem.o
memset.o : _memset.c
	gcc C_FLAGS -c _memset.c -o mem.o

# Produice a .o file with command handling functions
cmd_exec.o : _cmd_exec.c
	gcc C_FLAGS -c _cmd_exec.c -o cmd_exec.o
supcmd_exec.o : _supcmd_exec.c
	gcc C_FLAGS -c _supcmd_exec.c -o supcmd_exec.o
envi_funcs.o : _envi_funcs.c
	gcc C_FLAGS -c _envi_funcs.c -o envi_funcs.o
err_funcs.o : _error_funcs.c
	gcc C_FLAGS -c _error_funcs.c -o err_funcs.o

# =================================== #
# make argument to clean object files #
# =================================== #
clean :
	rm -rf *.o
