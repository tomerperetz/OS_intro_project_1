#include "argparser.h"

int ensureArgs(int argc, int expected_argc, char *argv[]) {
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

int isArgsValid(int argc, char *argv[]) {
	/*optional*/
	return TRUE;
}

void callHelper() {
	printf(HELPER);
}