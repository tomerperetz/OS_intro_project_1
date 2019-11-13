/*
====================================================================================================================
Description:
This lib contains all functions related to string handeling
====================================================================================================================
*/

#include "../Share/lib_errorHandler.h"
#include "../Share/hardCodedData.h"



int getCharindex(char desired_char, char *dest_str)
{

	/*
	Description: get index for first apperance of a given char
	parameters: 
			 - char desired_char - char that is being looked for
			 - char *dest_str - string to look for the char in
	Returns: int index if the char was found. ERR o.w
	*/
	
	int len = -1;
	len = strlen(dest_str);

	for (int i = 0; i<=len; i++)
	{
		if (dest_str[i] == desired_char)
		{
			return i;
		}
	}
	
	return ERR;

}

int getFirstIntFromString(char *dest_str, int last_index)
{
	/*
	Description: get first integer in a string with the structure: "X + Y". convert from string to int.
	parameters:
			 - char *dest_str - string to look for the int in
			 - int last_index - maximal index the int might be found in.
	Returns: int.
	*/

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
	/*
	Description: get last integer in a string with the structure: "X + Y". convert from string to int.
	parameters:
			 - char *dest_str - string to look for the int in
			 - int last_index - opertor index to initialize the first search index.
	Returns: int.
	*/

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


void add_sub_string_to_string(char dest_str[], char sub_str[], int start_idx) {
	int idx = 0;
	for (idx = 0; sub_str[idx] != END_OF_STR; idx++, start_idx++)
		dest_str[start_idx] = sub_str[idx];
	dest_str[start_idx] = END_OF_STR;

}

void replace_sub_string(char *string, int sub_str_start_idx, int sub_str_end_idx, char *new_sub_string) {
	char string_start[MAX_FATHER_ARG_INPUT_LEN], string_end[MAX_FATHER_ARG_INPUT_LEN];

	strcpy_s(string_end, MAX_FATHER_ARG_INPUT_LEN, &string[sub_str_end_idx + 1]);
	string[sub_str_start_idx] = END_OF_STR;
	strcpy_s(string_start, MAX_FATHER_ARG_INPUT_LEN, string);
	sprintf_s(string, MAX_FATHER_ARG_INPUT_LEN, "%s%s%s", string_start, new_sub_string, string_end);
	//add_sub_string_to_string(string, new_sub_string, sub_str_start_idx);
	//add_sub_string_to_string(string, string_end, sub_str_start_idx + strlen(new_sub_string));
}
