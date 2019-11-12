#include "argparser.h"

int ensureArgs(int argc, int expected_argc, char *argv[]) 
{
	/*
	Description: recieves user args and verify they are valid.
	parameters:
			 - int argc - number of args recieved.
			 - int expected_argc - number of args expected.
			 - char argv - args
	Returns: TRUE if the args are valid, ERROR o.w
	*/

	if (argc == 2 && (strcmp(argv[1], "-h") == YES || strcmp(argv[1], "--help") == YES) )
	{
		callHelper();
		return TRUE;
	}
	else if (argc == expected_argc){
		if (isArgsValid(argc, argv) == TRUE)
			return TRUE;
		else
			return ERROR;
	}
	else {
		return ERROR;
	}

}


void callHelper() {
	/*
	Description: prints help for the program and exits.
	parameters: none
	Returns: none
	*/

	printf(HELPER);
}