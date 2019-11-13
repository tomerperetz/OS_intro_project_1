
/*
====================================================================================================================
Description:
this lib is used for error handeling.
====================================================================================================================
*/


#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "hardCodedData.h"

# define ARGS_ERROR  "arguments error. please restart the function.\nYou may type -h for help.\n"
# define OPERATOR_ERROR  "Can't use supplied opertor: %c\nExiting Program\n"
# define STRCPY_ERROR "String copy error. please reset the program.\n"
static const char ERROR_ID_1_CONTENT[160] = \
"The given arguments are not in the correct format / number of arguments is incorrect.\n"\
"For more help please run the following command: ~<Project-Name> --help\n";

void raiseError(int error_id, const char *function_name, const char *file_path, int line, const char *description);

