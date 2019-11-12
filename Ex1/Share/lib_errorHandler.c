#include "lib_errorHandler.h"

void raiseError(int error_id, char *function_name , char *file_path, int line, char *description)
{
	printf("FATAL ERROR: ERROR NUMBER %d\n", error_id);
	printf("File: %s\n", file_path);
	printf("Function: %s\n", function_name);
	printf("Line: %d\n", line);
	printf("Description: %s\n", description);
	exit(ERROR);
}
