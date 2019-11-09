#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "hardCodedData.h"

static const int EXPECTED_ARGC = 2;
static const char HELPER[1000] = \
"===========================================================================================\n"\
"This program is fucking awesome\n"\
"Inputs: equation - bla bla\n"\
"Output: bla bla \n"\
"requierments: None\n"\
"===========================================================================================\n";


int ensureArgs(int argc, int expected_argc, char *argv[]);
int isArgsValid(int argc, char *argv[]);
void callHelper();

