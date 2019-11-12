#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>	
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>

//Const That Relevant For All Projects
# define ERROR -1
# define YES 0
# define TRUE 1
# define FALSE 1


//Const That Relevant For This Project Only
# define MAX_SON_ARG_INPUT_LEN 32
# define MAX_FATHER_ARG_INPUT_LEN 256

// errors
# define ARGS_ERROR  "arguments error. please restart the function.\nYou may type -h for help.\n"
# define OPERATOR_ERROR  "Can't use supplied opertor: %c\nExiting Program\n"