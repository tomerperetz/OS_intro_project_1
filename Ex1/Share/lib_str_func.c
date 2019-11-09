#include <stdio.h>
#include <string.h>


//================================================================
//This module contains all functions related to string handeling
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
			printf("sub char: %c found on index: %d\n", dest_str[i],i);
			return i;
		}
	}
	printf("char wasn't found\n");
	return -1;

}

int getFirstIntFromString(char *dest_str, int last_index)
{
	// add defines, delete prints
	int int_x = - 1;
	char char_x[33];
	long long int long_x = -1;

	for (int i = 0; i < last_index; i++)
	{
		char_x[i] = dest_str[i];
	}

	char_x[last_index] = '\0';
	int_x = atoi(char_x);
	long_x = atoll(char_x);

	printf("first number str: %s\n", char_x);
	printf("first number int: %d\n", int_x);
	printf("first number long: %lld\n", long_x);

	return int_x;
}

int getLastIntFromString(char *dest_str, int first_index)
{
	// add defines, delete prints
	int int_x = -1, last_i = 0, iter = 0;
	long long int long_x = -1;
	char char_x[33];

	for (int i = first_index; dest_str[i]!='\0'; i++)
	{
		char_x[iter] = dest_str[i];
		iter++;
	}

	char_x[iter] = '\0';
	int_x = atoi(char_x);
	long_x = atoll(char_x);
	printf("last number str: %s\n", char_x);
	printf("last number int: %d\n", int_x);
	printf("last number long: %lld\n", long_x);
	return int_x;
}

