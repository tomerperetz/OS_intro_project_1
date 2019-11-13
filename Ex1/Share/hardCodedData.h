#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>	
#include <string.h>
#include <windows.h>

//Const That Relevant For All Projects
static const int ERR = -1;
static const int EQUAL = 0;
static const int IS_TRUE = 1;
static const int IS_FALSE = 0;
static const char END_OF_STR = '\0';
static const char OPEN_PARENTHESIS = '(';
static const char CLOSE_PARENTHESIS = ')';

#define TIMEOUT_IN_MILLISECONDS 10000
#define BRUTAL_TERMINATION_CODE -10

//Const That Relevant For This Project Only
# define MAX_SON_ARG_INPUT_LEN 32
# define MAX_FATHER_ARG_INPUT_LEN 256

// errors
# define ARGS_ERROR  "arguments error. please restart the function.\nYou may type -h for help.\n"
# define OPERATOR_ERROR  "Can't use supplied opertor: %c\nExiting Program\n"
# define STRCPY_ERROR "String copy error. please reset the program.\n"