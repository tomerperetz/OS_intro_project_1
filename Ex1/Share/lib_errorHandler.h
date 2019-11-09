#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "hardCodedData.h"

static const int ERROR_ID_1 = 1;
static const int ERROR_ID_GLOBAL= -1;
static const char ERROR_ID_1_CONTENT[160] = \
"The given arguments are not in the correct format / number of arguments is incorrect.\n"\
"For more help please run the following command: ~<Project-Name> --help\n";

void raiseError(int error_id, char *file_path,char *line, char *function_name);


