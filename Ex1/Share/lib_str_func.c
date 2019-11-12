#include <stdio.h>
#include <string.h>
#include "../Share/lib_errorHandler.h"
#include "../Share/hardCodedData.h"

//================================================================
//This lib contains all functions related to string handeling
//================================================================


int getCharindex(char desired_char, char *dest_str)
{
	// add defines, delete prints
	int len = -1;
	len = strlen(dest_str);

	for (int i = 0; i<=len; i++)
	{
		if (dest_str[i] == desired_char)
		{
			return i;
		}
	}
	
	return ERROR;

}

int getFirstIntFromString(char *dest_str, int last_index)
{
	int int_x = - 1;
	char char_x[MAX_SON_ARG_INPUT_LEN];
	
	for (int i = 0; i < last_index; i++)
	{
		char_x[i] = dest_str[i];
	}

	char_x[last_index] = '\0';
	int_x = atoi(char_x);
	
	return int_x;
}

int getLastIntFromString(char *dest_str, int first_index)
{
	int int_x = -1, last_i = 0, iter = 0;
	char char_x[MAX_SON_ARG_INPUT_LEN];

	for (int i = first_index; dest_str[i]!='\0'; i++)
	{
		char_x[iter] = dest_str[i];
		iter++;
	}

	char_x[iter] = '\0';
	int_x = atoi(char_x);
	return int_x;
}
