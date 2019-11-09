#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>


//================================================================
//This module contains all functions related to string handeling
//================================================================


int getCharindex(char desired_char, char *dest_str);

int getFirstIntFromString(char *dest_str, int last_index);

int getLastIntFromString(char *dest_str, int first_index);
